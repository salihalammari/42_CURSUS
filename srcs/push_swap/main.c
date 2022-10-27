/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:47 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:59:39 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_ps	*a;
	t_ps	*b;
	int		*sorted_array;

	i = 0;
	if (ac >= 2)
	{
		a = ft_ps_create();
		b = ft_ps_create();
		while (++i < ac)
			ps_parsing(av[i], a);
		sorted_array = ft_ps_array_validation(a);
		ft_sort_init(a, b, sorted_array);
		ft_destroy(a);
		ft_destroy(b);
	}
	return (0);
}
