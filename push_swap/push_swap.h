/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:44 by slammari          #+#    #+#             */
/*   Updated: 2022/11/09 19:30:53 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define SA 4
# define SB 5
# define RRA 6
# define RRB 7

# define CHECKER 1
# define NOCHECKER 0

# define LONG_MAX 9223372036854775807
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
	int				index;
}	t_node;

typedef struct s_deque
{
	t_node	*top;
	t_node	*bottom;
	int		total;
}	t_deque;

/* parsing*/
void		parsing(char **argv, t_deque *a);
/* method */
void		rotate(t_deque *deque);
void		reverse_rotate(t_deque *deque);
void		ft_swap(t_deque *deque);
void		ft_push(t_deque *dst, t_deque *src);
/* operation */
void		operation_r(int op, t_deque *a, t_deque *b, int isChecker);
void		operation(int op, t_deque *a, t_deque *b, int isChecker);
/* sorting */
void		a_to_b(t_deque *a, t_deque *b, int chunk);
void		b_to_a(t_deque *a, t_deque *b);
/* sorting_small */
int			is_sorted(t_deque *a);
void		sort_three(t_deque *a);
void		sort_four(t_deque *a, t_deque *b);
void		sort_five(t_deque *a, t_deque *b);
/* utils */
int			ft_error(void);
void		init_deque(t_deque *deque);
void		free_deque(t_deque *deque);
long long	ft_atoll(const char *s);
int			ft_isnum(const char *s);

#endif
