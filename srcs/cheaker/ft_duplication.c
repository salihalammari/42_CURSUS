/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:21:49 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:42:41 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ch_duplication(t_ps *a)
{
	int		i;
	int		j;
	t_node	*buf;
	t_node	*node;

	i = a->count;
	buf = a->head;
	while (i--)
	{
		j = i;
		node = buf->next;
		while (j--)
		{
			if (buf->data == node->data)
				ps_error(2);
			node = node->next;
		}
		buf = buf->next;
	}	
}