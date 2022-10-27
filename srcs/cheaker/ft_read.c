/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:22:31 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:42:20 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ch_read(char *line, t_ps *a, t_ps *b)
{
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		checker(line, a, b);
		free(line);
	}
}