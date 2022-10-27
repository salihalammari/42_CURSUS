/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:23 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:57:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int ft_ps_data_min(t_node *node)
{
    int data;
    
    data = node->data;
    while(data)
    {
        if(data > node->data)
            data = node->data;
        node = node->next;
    }
    return(data);
}

int ft_ps_data_max(t_node *node)
{
    int data;

    data = node->data;
    while(data)
    {
        if(data < node->data)
            data = node->data;
        node = node->next;
    }
    return(data);
}

int	ft_ps_min(t_ps *ps)
{
	int		idx;
	int		data;
	int		min_data;
	t_node	*node;

	idx = 0;
	node = ps->head;
	min_data = ps_data_min(node);
	while (node)
	{
		data = node->data;
		if (data == min_data)
			break ;
		idx++;
		node = node->next;
	}
	if (idx >= (ps->count + 1) / 2)
		idx = (ps->count - idx) * -1;
	return (idx);
}

int	ft_ps_max(t_ps *ps)
{
	int		max_data;
	int		data;
	int		idx;
	t_node	*node;

	idx = 0;
	data = 0;
	node = ps->head;
	max_data = ps_data_max(node);
	while (node)
	{
		data = node->data;
		if (data == max_data)
			break ;
		idx++;
		node = node->next;
	}
	idx++;
	if (idx >= (ps->count + 1) / 2)
		idx = (ps->count - idx) * -1;
	return (idx);
}

int	ft_ps_mid(int top, t_ps *ps)
{
	int		idx;
	t_node	*node;

	idx = 1;
	node = ps->head;
	while (node->next)
	{
		if (top > node->data && top < node->next->data)
			break ;
		idx++;
		node = node->next;
	}
	if (idx >= (ps->count + 1) / 2)
		idx = (ps->count - idx) * -1;
	return (idx);
}
