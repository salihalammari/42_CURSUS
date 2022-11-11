/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:40 by slammari          #+#    #+#             */
/*   Updated: 2022/11/08 21:55:14 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_dup_and_indexing(t_deque *a)
{
	t_node	*cur;
	t_node	*cur_next;

	cur = a->top;
	while (cur)
	{
		cur_next = cur->next;
		while (cur_next)
		{
			if (cur->num > cur_next->num)
				cur->index++;
			else if (cur->num < cur_next->num)
				cur_next->index++;
			else
				ft_error();
			cur_next = cur_next->next;
		}
		cur = cur->next;
	}
}

static void	add_new_node(int num, t_deque *a)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(EXIT_FAILURE);
	new->num = num;
	new->index = 0;
	if (a->total == 0)
	{
		a->top = new;
		a->bottom = new;
	}
	else
	{
		new->prev = a->bottom;
		new->next = NULL;
		a->bottom->next = new;
		a->bottom = new;
	}
	a->total++;
}

static void	add_valid_input(const char *s, t_deque *a)
{
	long long	num;

	num = ft_atoll(s);
	if (!(ft_isnum(s)) || num > INT_MAX || num < INT_MIN)
		ft_error();
	add_new_node(num, a);
}

static void	split_input(const char *s, t_deque *a)
{
	char	**sp_str;
	int		i;

	sp_str = ft_split(s, ' ');
	if (sp_str == NULL)
		exit(EXIT_FAILURE);
	if (!sp_str[0])
		ft_error();
	i = -1;
	while (sp_str[++i] != NULL)
	{
		add_valid_input(sp_str[i], a);
		free(sp_str[i]);
	}
	free(sp_str);
}

void	parsing(char **argv, t_deque *a)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
			split_input(argv[i], a);
		else
			add_valid_input(argv[i], a);
	}
	check_dup_and_indexing(a);
}
