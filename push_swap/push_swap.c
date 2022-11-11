/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:42 by slammari          #+#    #+#             */
/*   Updated: 2022/11/10 10:07:38 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_chunk(int x)
{
	if (x <= 250)
		return (15);
	else
		return (25);
}

static void	ft_push_swap(t_deque *a, t_deque *b)
{
	if (a->total == 2)
		operation(SA, a, NULL, NOCHECKER);
	else if (a->total == 3)
		sort_three(a);
	else if (a->total == 4)
		sort_four(a, b);
	else if (a->total == 5)
		sort_five(a, b);
	else
	{
		a_to_b(a, b, calc_chunk(a->total));
		b_to_a(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	if (argc <= 2)
		return (0);
	init_deque(&a);
	parsing(argv, &a);
	if (is_sorted(&a))
	{
		free_deque(&a);
		return (0);
	}
	init_deque(&b);
	ft_push_swap(&a, &b);
	free_deque(&a);
	free_deque(&b);
	return (0);
}
