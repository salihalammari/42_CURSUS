/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:41 by slammari          #+#    #+#             */
/*   Updated: 2022/10/26 11:48:42 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps	*ps_create(void)
{
	t_ps	*ps;

	ps = (t_ps *)ft_calloc(1, sizeof(t_ps));
	if (!ps)
		ps_error(2);
	return (ps);
}

int	ps_left_add(t_ps *ps, int data)
{
	t_node	*buf;
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (FALSE);
	new->data = data;
	if (ps->count == 0)
		ps->head = new;
	else
	{
		buf = ps->head;
		buf->prev = new;
		new->next = buf;
		ps->head = new;
	}
	ps->count += 1;
	return (TRUE);
}

int	ps_right_add(t_ps *ps, int data)
{
	t_node	*buf;
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (FALSE);
	new->data = data;
	if (ps->count == 0)
		ps->head = new;
	else
	{
		buf = ps_get_node(ps, ps->count - 1);
		buf->next = new;
		new->prev = buf;
	}
	ps->count += 1;
	return (TRUE);
}

t_node	*ps_left_pop(t_ps *ps)
{
	t_node	*buf;

	if (!ps->count)
		return (NULL);
	buf = ps->head;
	ps->head = buf->next;
	if (ps->count != 1)
		ps->head->prev = NULL;
	buf->prev = NULL;
	buf->next = NULL;
	ps->count -= 1;
	return (buf);
}

t_node	*ps_right_pop(t_ps *ps)
{
	t_node	*buf;

	if (ps->count == 0)
		return (NULL);
	buf = ps_get_node(ps, ps->count - 1);
	if (ps->count == 1)
		ps->head = NULL;
	else
		buf->prev->next = NULL;
	buf->prev = NULL;
	buf->next = NULL;
	ps->count -= 1;
	return (buf);
}
