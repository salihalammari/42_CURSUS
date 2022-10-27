/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:23:02 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:41:32 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	checker(char *line, t_ps *a, t_ps *b)
{
	if (!ch_command(line, (ft_strlen(line) - 1)))
		ps_error(2);
	if (ft_strncmp(line, "sa", 2) == 0 || ft_strncmp(line, "ss", 2) == 0)
		ps_swap(a, NONE);
	if (ft_strncmp(line, "sb", 2) == 0 || ft_strncmp(line, "ss", 2) == 0)
		ps_swap(b, NONE);
	if (ft_strncmp(line, "pa", 2) == 0)
		ps_push(b, a, NONE);
	if (ft_strncmp(line, "pb", 2) == 0)
		ps_push(a, b, NONE);
	if ((ft_strncmp(line, "ra", 2) == 0 || ft_strncmp(line, "rr", 2) == 0) && \
		ft_strncmp("rrr", line, 3) != 0)
		ps_rotate(a, NONE);
	if ((ft_strncmp(line, "rb", 2) == 0 || ft_strncmp(line, "rr", 2) == 0) && \
		ft_strncmp("rrr", line, 3) != 0)
		ps_rotate(b, NONE);
	if (ft_strncmp(line, "rra", 3) == 0 || ft_strncmp("rrr", line, 3) == 0)
		ps_reverse_rotate(a, NONE);
	if (ft_strncmp(line, "rrb", 3) == 0 || ft_strncmp("rrr", line, 3) == 0)
		ps_reverse_rotate(b, NONE);
}

int	main(int ac, char *av[])
{
	int		i;
	t_ps	*a;
	t_ps	*b;
	char	*line;

	i = 0;
	line = NULL;
	if (ac >= 2)
	{
		a = ps_create();
		b = ps_create();
		while (++i < ac)
			ps_parsing(av[i], a);
		ch_duplication(a);
		ch_read(line, a, b);
		if (ch_is_sorted(a) && !b->count)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ps_destroy(a);
		ps_destroy(b);
	}
	return (0);
}