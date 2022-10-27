/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:45 by slammari          #+#    #+#             */
/*   Updated: 2022/10/26 11:48:46 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_error(int fd)
{
	if (fd)
		ft_putstr_fd("Error\n", fd);
	exit(1);
}

t_node	*ps_get_node(t_ps *ps, int position)
{
	t_node	*buf;

	if (ps->count == 0)
		return (NULL);
	buf = ps->head;
	while (position--)
		buf = buf->next;
	return (buf);
}

int	ps_atoi(const char *str)
{
	size_t	i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
			ps_error(2);
		i++;
	}
	if (str[i])
		ps_error(2);
	return (num * sign);
}

void	ps_display(int type)
{
	char	*tp;
	char	*ps;
	char	*str;

	if (type == NONE)
		return ;
	if (type == SA || type == SB || type == SS)
		tp = "s";
	else if (type == PA || type == PB)
		tp = "p";
	else if (type == RA || type == RB || type == RR)
		tp = "r";
	else if (type == RRA || type == RRB || type == RRR)
		tp = "rr";
	if (type == SA || type == PA || type == RA || type == RRA)
		ps = "a";
	else if (type == SB || type == PB || type == RB || type == RRB)
		ps = "b";
	else if (type == RR || type == RRR)
		ps = "r";
	str = ft_strjoin(tp, ps);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free(str);
	str = NULL;
}
