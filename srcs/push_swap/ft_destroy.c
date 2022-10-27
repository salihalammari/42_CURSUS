/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:20 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:43:33 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_delete_node(t_ps *ps)
{
	t_node	*buf;
	t_node	*del;

	buf = ps->head;
	while (buf->next)
	{
		del = buf;
		free(del);
		del = NULL;
		buf = buf->next;
	}
	free(buf);
	buf = NULL;
}

void	ps_destroy(t_ps *ps)
{
	if (ps->head)
		ps_delete_node(ps);
	free(ps);
	ps = NULL;
}