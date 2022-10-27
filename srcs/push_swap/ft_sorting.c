/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:39 by slammari          #+#    #+#             */
/*   Updated: 2022/10/26 11:48:40 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort_init(t_ps *a, t_ps *b, int *sorted_array)
{
	if (a->count == 2)
		ps_sort2(a);
	else if (a->count == 3)
		ps_sort3(a);
	else if (a->count > 3)
		push_swap(a, b, sorted_array);
}

void	ps_sort2(t_ps *a)
{
	if (a->head->data > a->head->next->data)
		ps_swap(a, SA);
}

void	ps_sort3(t_ps *a)
{
	int	left;
	int	right;
	int	mid;

	left = a->head->data;
	mid = a->head->next->data;
	right = a->head->next->next->data;
	if (right > left && left > mid && right > mid)
		ps_swap(a, SA);
	else if (mid > left && left > right && mid > right)
		ps_reverse_rotate(a, RRA);
	else if (left > right && right > mid && left > mid)
		ps_rotate(a, RA);
	else if (mid > right && right > left && mid > left)
	{
		ps_swap(a, SA);
		ps_rotate(a, RA);
	}
	else if (left > mid && mid > right && left > right)
	{
		ps_swap(a, SA);
		ps_reverse_rotate(a, RRA);
	}
}

void	ps_sort_last(t_ps *a)
{
	int	i;

	i = ps_min(a);
	ps_rotate1(a, i, RA, RRA);
}
