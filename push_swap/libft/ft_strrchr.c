/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:08:11 by slammari          #+#    #+#             */
/*   Updated: 2021/12/03 19:38:29 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				n;
	unsigned char	t;

	n = ft_strlen (s);
	t = c;
	while (n >= 0)
	{
		if (s[n] == t)
			return ((char *)s + n);
		n--;
	}
	return (NULL);
}
