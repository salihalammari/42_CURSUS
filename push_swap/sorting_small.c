/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:46 by slammari          #+#    #+#             */
/*   Updated: 2022/11/10 03:58:44 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *a)
{
	t_node	*cur;
	t_node	*cur_next;

	cur = a->top;
	while (cur->next)
	{
		cur_next = cur->next;
		if (cur->index > cur_next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	sort_three_util(int first, int second, int third, t_deque *a)
{
	if (first < second)
	{
		if (first < third)
		{
			operation_r(RRA, a, NULL, NOCHECKER);
			operation(SA, a, NULL, NOCHECKER);
		}
		else
			operation_r(RRA, a, NULL, NOCHECKER);
	}
	else
	{
		if (first > third && second > third)
		{
			operation_r(RA, a, NULL, NOCHECKER);
			operation(SA, a, NULL, NOCHECKER);
		}
		else if (first > third && second < third)
			operation_r(RA, a, NULL, NOCHECKER);
		else
			operation(SA, a, NULL, NOCHECKER);
	}
}

void	sort_three(t_deque *a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(a))
		return ;
	first = a->top->index;
	second = a->top->next->index;
	third = a->bottom->index;
	sort_three_util(first, second, third, a);
}

void	sort_four(t_deque *a, t_deque *b)
{
	int	second;
	int	third;
	int	last;

	second = a->top->next->index;
	third = a->top->next->next->index;
	last = a->bottom->index;
	if (second == 0)
		operation(SA, a, NULL, NOCHECKER);
	else if (third == 0)
	{
		operation_r(RA, a, NULL, NOCHECKER);
		operation_r(RA, a, NULL, NOCHECKER);
	}
	else if (last == 0)
		operation_r(RRA, a, NULL, NOCHECKER);
	operation(PB, a, b, NOCHECKER);
	sort_three(a);
	operation(PA, a, b, NOCHECKER);
}

void	sort_five(t_deque *a, t_deque *b)
{
	while (a->total > 3)
	{
		if (a->top->index < 2)
			operation(PB, a, b, NOCHECKER);
		else
			operation_r(RA, a, NULL, NOCHECKER);
	}
	sort_three(a);
	while (b->total)
		operation(PA, a, b, NOCHECKER);
	if (a->top->index != 0)
		operation(SA, a, b, NOCHECKER);
}
