/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <ldi-fior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:20:03 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/02/29 17:36:23 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

typedef struct s_trgt
{
	int		tmp_where;
	int		tmp_which;
	int		where;
	int		which;
	int		tmp_moves;
	int		moves;
}	t_trgt;

typedef struct s_hlf
{
	int		half_a;
	int		half_b;
}	t_hlf;

typedef struct s_mm
{
	int		max_idx_a;
	int		min_idx_a;
	int		max_idx_b;
	int		min_idx_b;
}	t_mm;

typedef struct s_stack
{
	int		*stk_a;
	int		len_a;
	int		*stk_b;
	int		len_b;
	t_trgt	trgt;
	t_hlf	half;
	t_mm	mm;
}	t_stack;

void	init(t_stack *stk);
int		init_stack(t_stack *stk, int argc, char **argv);
int		alloc_stack(t_stack *stk);
char	**ft_split(char *str, char c);
int		ft_atoi(const char *nptr);
int		ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dest, void *src, int n);
int		quit_and_free(t_stack *stk, int error);
int		free_matrix(char **mat);
int		check_arg(int argc, char **argv);
int		ch_nbr(char	*str, int argc);
int		ch_double(t_stack *stk);
void	sa(t_stack *stk);
void	sb(t_stack *stk);
void	ss(t_stack *stk);
void	pa(t_stack *stk);
void	pb(t_stack *stk);
void	ra(t_stack *stk);
void	rb(t_stack *stk);
void	rr(t_stack *stk);
void	rra(t_stack *stk);
void	rrb(t_stack *stk);
void	rrr(t_stack *stk);
void	get_max_min(t_stack *stk);
int		is_sorted(t_stack *stk);
void	sort_trhee(t_stack *stk);
void	find_half(t_stack *stk, char stack);
void	get_target_a(t_stack *stk, int i);
void	get_target_b(t_stack *stk, int i);
void	count_moves_a(t_stack *s);
void	count_moves_b(t_stack *s);
void	upper_half(t_stack *s);
void	lower_half(t_stack *s);
void	one_up_one_down(t_stack *s);
void	push_swap(t_stack *stk, int n_arg, int argc, char **argv);
void	best_move_a(t_stack *s);
void	best_move_b(t_stack *s);
void	sort(t_stack *stk);
void	final_move(t_stack *s);
void	both_up(t_stack *s);
void	both_down(t_stack *s);
void	down_up(t_stack *s);
void	up_down(t_stack *s);
void	sort_and_push(t_stack *s, char str);

#endif