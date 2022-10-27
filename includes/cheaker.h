/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheaker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:39:00 by slammari          #+#    #+#             */
/*   Updated: 2022/10/27 11:39:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

int		ch_is_sorted(t_ps *a);
void	ch_duplication(t_ps *a);
int		ch_command(char *line, int l);
void	checker(char *line, t_ps *a, t_ps *b);
void	ch_read(char *line, t_ps *a, t_ps *b);

#endif
