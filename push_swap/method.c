/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:36 by slammari          #+#    #+#             */
/*   Updated: 2022/11/07 16:00:50 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->total < 2)
		return ;
	node = deque->top;
	deque->top = node->next;
	deque->top->prev = NULL;
	node->next = NULL;
	node->prev = deque->bottom;
	deque->bottom->next = node;
	deque->bottom = node;
}

void	reverse_rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->total < 2)
		return ;
	node = deque->bottom;
	deque->bottom = node->prev;
	deque->bottom->next = NULL;
	node->prev = NULL;
	node->next = deque->top;
	deque->top->prev = node;
	deque->top = node;
}

void	ft_swap(t_deque *deque)
{
	t_node	*node1;
	t_node	*node2;

	if (deque->total < 2)
		return ;
	node1 = deque->top->next;
	node2 = deque->top;
	node2->next = node1->next;
	node2->prev = node1;
	deque->top = node1;
	if (node2->next)
		node2->next->prev = node2;
	else
		deque->bottom = node2;
	node1->prev = NULL;
	node1->next = node2;
}

void	ft_push(t_deque *dst, t_deque *src)
{
	t_node	*node;

	if (src->total == 0)
		return ;
	node = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	node->next = dst->top;
	node->prev = NULL;
	if (dst->top)
		dst->top->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->total++;
	src->total--;
}
