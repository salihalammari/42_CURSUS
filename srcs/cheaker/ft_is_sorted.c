/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:22:13 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:42:31 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ch_is_sorted(t_ps *a)
{
	int		i;
	t_node	*node;

	i = 1;
	node = a->head;
	while (i < a->count)
	{
		if (node->data > node->next->data)
			return (FALSE);
		node = node->next;
		i++;
	}
	return (TRUE);
}
