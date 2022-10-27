/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:29 by slammari          #+#    #+#             */
/*   Updated: 2022/10/26 11:48:30 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

void	ps_pivot(t_ps *a, t_ps *b, int *arr)
{
	int	i;
	int	pivot1;
	int	pivot2;

	pivot1 = arr[a->count / 3];
	pivot2 = arr[(a->count * 2) / 3];
	i = a->count;
	while (i)
	{
		if (a->head->data < pivot1)
		{
			ps_push(a, b, PB);
			ps_rotate(b, RB);
		}
		else if (a->head->data < pivot2)
			ps_push(a, b, PB);
		else
			ps_rotate(a, RA);
		i--;
	}
}

void	ps_min_rotate(t_ps *a, t_ps *b, int *idx_a, int *idx_b)
{
	int		i;
	int		i_a;
	int		i_b;
	t_node	*node;

	i = 0;
	node = b->head;
	while (i < b->count)
	{
		i_a = ps_get_index(node->data, a);
		if (i >= (b->count + 1) / 2)
			i_b = (b->count - i) * -1;
		else
			i_b = i;
		if (i == 0 || ps_bigger(*idx_a, *idx_b, i_a, i_b))
		{
			*idx_a = i_a;
			*idx_b = i_b;
		}
		node = node->next;
		i++;
	}
}

int	ps_get_index(int top_num, t_ps *ps)
{
	if (top_num < ps_data_min(ps->head))
		return (ps_min(ps));
	else if (top_num > ps_data_max(ps->head))
		return (ps_max(ps));
	else
		return (ps_mid(top_num, ps));
}

int	ps_bigger(int a, int b, int i_a, int i_b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (i_a < 0)
		i_a *= -1;
	if (i_b < 0)
		i_b *= -1;
	if (a + b > i_a + i_b)
		return (1);
	return (0);
}
