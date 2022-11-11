/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:07:25 by slammari          #+#    #+#             */
/*   Updated: 2021/12/03 19:08:55 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	f;
	size_t	r;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		f = 0;
		r = ft_strlen(s1);
		while (s1[f] && ft_strchr(set, s1[f]))
			f++;
		while (s1[r - 1] && ft_strchr(set, s1[r - 1]) && r > f)
			r--;
		str = (char *)malloc(sizeof(char) * (r - f + 1));
		if (str)
			ft_strlcpy(str, &s1[f], r - f + 1);
	}
	return (str);
}
