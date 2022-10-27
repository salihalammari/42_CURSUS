/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:34 by slammari          #+#    #+#             */
/*   Updated: 2022/10/26 11:48:35 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ps_push(t_ps *a, t_ps *b, int type)
{
	t_node	*node;

	if (a->count)
	{		
		node = ps_left_pop(a);
		if (!node)
			return ;
		ps_left_add(b, node->data);
		ps_display(type);
		free(node);
		node = NULL;
	}
}
