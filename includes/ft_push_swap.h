/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:39:39 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:39:41 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ps_def.h"
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_ps
{
	int		count;
	t_node	*head;
}			t_ps;

void	ps_error(int fd);
t_node	*ps_get_node(t_ps *ps, int position);
int		ps_atoi(const char *str);
void	ps_display(int type);
t_ps	*ps_create(void);
int		ps_left_add(t_ps *ps, int data);
int		ps_right_add(t_ps *ps, int data);
t_node	*ps_left_pop(t_ps *ps);
t_node	*ps_right_pop(t_ps *ps);
int		*ps_array_validation(t_ps *ps);
int		*ps_array_add(t_ps *ps);
int		ps_array_sort(int *arr, int len);
int		ps_data_min(t_node *node);
int		ps_data_max(t_node *node);
int		ps_min(t_ps *ps);
int		ps_max(t_ps *ps);
int		ps_mid(int num, t_ps *ps);
void	ps_push(t_ps *a, t_ps *b, int type);
void	ps_swap(t_ps *ps, int type);
void	ps_rotate1(t_ps *ps, int idx, int type1, int type2);
void	ps_rotate2(t_ps *a, t_ps *b, int *idx_a, int *idx_b);
void	ps_rotate(t_ps *ps, int type);
void	ps_reverse_rotate(t_ps *ps, int type);
void	ps_parsing(const char *str, t_ps *a);
void	ps_sort_init(t_ps *a, t_ps *b, int *sorted_array);
void	ps_sort2(t_ps *a);
void	ps_sort3(t_ps *a);
void	ps_sort_last(t_ps *a);
void	push_swap(t_ps *a, t_ps *b, int *arr);
void	ps_pivot(t_ps *a, t_ps *b, int *arr);
void	ps_min_rotate(t_ps *a, t_ps *b, int *idx_a, int *idx_b);
int		ps_get_index(int num, t_ps *ps);
int		ps_bigger(int a, int b, int i_a, int i_b);
void	ps_destroy(t_ps *ps);
void	ps_delete_node(t_ps *ps);

#endif