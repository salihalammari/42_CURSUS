/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:18 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:43:21 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ps_array_validation(t_ps *ps)
{
	int	len;
	int	sorted;
	int	*array;

	len = ps->count;
	array = ps_array_add(ps);
	if (!array)
		ps_error(2);
	sorted = ps_array_sort(array, len);
	if (!sorted)
		ps_error(2);
	else if (sorted == -1)
		ps_error(0);
	return (array);
}

int	*ps_array_add(t_ps *ps)
{
	int		i;
	int		*array;
	t_node	*buf;

	i = 0;
	buf = ps->head;
	array = (int *)ft_calloc(ps->count, sizeof(int));
	if (!array)
		return (FALSE);
	while (i < ps->count)
	{
		array[i++] = buf->data;
		buf = buf->next;
	}
	return (array);
}

int	ps_array_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	flag;

	i = 0;
	flag = -1;
	while (i < len)
	{
		j = i;
		while (++j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				flag = 2;
			}
			if (arr[i] == arr[j])
				return (FALSE);
		}
		i++;
	}
	return (flag);
}
