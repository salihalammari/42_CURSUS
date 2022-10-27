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

int ps_data_min(t_node *node)
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

int ps_data_max(t_node *node)
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

int ps_min(t_ps *ps)
{
    int
}