/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:29 by slammari          #+#    #+#             */
/*   Updated: 2022/11/08 05:11:08 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*gnl_strchr(const char *s, int c)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}

static char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcat(result, s2, s1_len + s2_len + 1);
	free((void *)s1);
	return (result);
}

static char	*split_line(char **storage)
{
	char	*ptr_newline;
	char	*next_line;
	char	*get_line;

	ptr_newline = gnl_strchr(*storage, '\n');
	next_line = ft_strdup(ptr_newline + 1);
	get_line = ft_substr(*storage, 0,
			ft_strlen(*storage) - ft_strlen(ptr_newline) + 1);
	free(*storage);
	*storage = next_line;
	return (get_line);
}

static char	*read_last(char	**storage)
{
	char	*last_line;

	if (gnl_strchr(*storage, '\n'))
		return (split_line(storage));
	else
	{
		if (**storage != '\0')
			last_line = ft_strdup(*storage);
		else
			last_line = NULL;
		free(*storage);
		*storage = NULL;
		return (last_line);
	}
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*buf;
	int			read_size;
	int			error_flag;

	error_flag = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !buf)
		error_flag = 1;
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size >= READ_SUCCESS && !error_flag)
	{
		buf[read_size] = '\0';
		storage[fd] = gnl_strjoin(storage[fd], buf);
		if (gnl_strchr(storage[fd], '\n'))
		{
			free(buf);
			return (split_line(&storage[fd]));
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (read_size == READ_EOF && storage[fd] && !error_flag)
		return (read_last(&storage[fd]));
	return (NULL);
}
