/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:52 by slammari          #+#    #+#             */
/*   Updated: 2022/11/08 09:47:03 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	init_deque(t_deque *deque)
{
	deque->top = NULL;
	deque->bottom = NULL;
	deque->total = 0;
}

void	free_deque(t_deque *deque)
{
	t_node	*tmp;

	tmp = deque->top;
	while (deque->top)
	{
		deque->top = deque->top->next;
		free(tmp);
		tmp = deque->top;
	}
}

int	ft_isnum(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

long long	ft_atoll(const char *s)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (((*s >= 9 && *s <= 13) || *s == ' ') && *s)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s) && *s)
	{
		if ((sign > 0 && result > LONG_MAX / 10) || \
			(sign < 0 && result > LONG_MAX + 1 / 10))
			break ;
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}
