/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:38 by slammari          #+#    #+#             */
/*   Updated: 2022/11/08 19:20:17 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_r(int op, t_deque *a, t_deque *b, int ischecker)
{
	if (op == RA)
	{
		rotate(a);
		if (!ischecker)
			write(1, "ra\n", 3);
	}
	else if (op == RB)
	{
		rotate(b);
		if (!ischecker)
			write(1, "rb\n", 3);
	}
	else if (op == RRA)
	{
		reverse_rotate(a);
		if (!ischecker)
			write(1, "rra\n", 4);
	}
	else if (op == RRB)
	{
		reverse_rotate(b);
		if (!ischecker)
			write(1, "rrb\n", 4);
	}
}

void	operation(int op, t_deque *a, t_deque *b, int ischecker)
{
	if (op == PA)
	{
		ft_push(a, b);
		if (!ischecker)
			write(1, "pa\n", 3);
	}
	else if (op == PB)
	{
		ft_push(b, a);
		if (!ischecker)
			write(1, "pb\n", 3);
	}
	else if (op == SA)
	{
		ft_swap(a);
		if (!ischecker)
			write(1, "sa\n", 3);
	}
	else if (op == SB)
	{
		ft_swap(b);
		if (!ischecker)
			write(1, "sb\n", 3);
	}
}
