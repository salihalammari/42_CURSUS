/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:16:27 by slammari          #+#    #+#             */
/*   Updated: 2022/11/10 11:22:20 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <limits.h>

# define READ_EOF 0
# define READ_SUCCESS 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

/* method_bonus */
void	ss(t_deque *a, t_deque *b, int isChecker);
void	rr(t_deque *a, t_deque *b, int isChecker);
void	rrr(t_deque *a, t_deque *b, int isChecker);
#endif