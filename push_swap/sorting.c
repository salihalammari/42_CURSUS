/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:49 by slammari          #+#    #+#             */
/*   Updated: 2022/11/08 19:21:25 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	route_rb_or_rrb(t_deque *deque, int max_index)
{
	t_node	*cur;
	int		loc;

	loc = 1;
	cur = deque->top;
	while (cur->index != max_index)
	{
		loc++;
		cur = cur->next;
	}
	if (loc <= deque->total / 2)
		return (1);
	else
		return (0);
}

void	a_to_b(t_deque *a, t_deque *b, int chunk)
{
	int	criteria;

	criteria = 0;
	while (a->total)
	{
		if (a->top->index <= criteria)
		{
			operation(PB, a, b, NOCHECKER);
			criteria++;
		}
		else if (a->top->index <= criteria + chunk)
		{
			operation(PB, a, b, NOCHECKER);
			operation_r(RB, NULL, b, NOCHECKER);
			criteria++;
		}
		else
		{
			if (a->bottom->index <= criteria + chunk)
				operation_r(RRA, a, NULL, NOCHECKER);
			else
				operation_r(RA, a, NULL, NOCHECKER);
		}
	}
}

void	b_to_a(t_deque *a, t_deque *b)
{
	int	max_index ;

	while (b->total)
	{
		max_index = b->total - 1;
		if (route_rb_or_rrb(b, max_index))
		{
			while (b->top->index != max_index)
				operation_r(RB, NULL, b, NOCHECKER);
		}
		else
		{
			while (b->top->index != max_index)
				operation_r(RRB, NULL, b, NOCHECKER);
		}
		operation(PA, a, b, NOCHECKER);
	}
}
