/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:34 by slammari          #+#    #+#             */
/*   Updated: 2022/11/08 06:44:06 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_deque *a, t_deque *b, int isChecker)
{
	ft_swap(a);
	ft_swap(b);
	if (!isChecker)
		write(1, "ss\n", 3);
}

void	rr(t_deque *a, t_deque *b, int isChecker)
{
	rotate(a);
	rotate(b);
	if (!isChecker)
		write(1, "rr\n", 3);
}

void	rrr(t_deque *a, t_deque *b, int isChecker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!isChecker)
		write(1, "rrr\n", 3);
}
