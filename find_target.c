/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <ldi-fior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:17:32 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/02/28 14:00:44 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_a(t_stack *s, int i)
{
	int	j;

	s->trgt.tmp_where = 0;
	s->trgt.tmp_which = i;
	if (s->stk_a[i] < s->stk_b[s->mm.min_idx_b]
		|| s->stk_a[i] > s->stk_b[s->mm.max_idx_b])
		s->trgt.tmp_where = s->mm.max_idx_b;
	j = -1;
	while (++j < s->len_b - 1)
	{
		if (s->stk_a[i] < s->stk_b[j] && s->stk_a[i] > s->stk_b[j + 1])
			s->trgt.tmp_where = j + 1;
	}
}

void	get_target_b(t_stack *s, int i)
{
	int	j;

	s->trgt.tmp_which = 0;
	s->trgt.tmp_where = i;
	if (s->stk_b[i] < s->stk_a[s->mm.min_idx_a]
		|| s->stk_b[i] > s->stk_a[s->mm.max_idx_a])
		s->trgt.tmp_which = s->mm.min_idx_a;
	j = -1;
	while (++j < s->len_a - 1)
	{
		if (s->stk_b[i] > s->stk_a[j] && s->stk_b[i] < s->stk_a[j + 1])
			s->trgt.tmp_which = j + 1;
	}
}

static void	move(t_stack *s, char stk)
{
	if (stk == 'a')
	{
		if (s->trgt.tmp_which == 0 || s->trgt.tmp_moves < s->trgt.moves)
		{
			s->trgt.which = s->trgt.tmp_which;
			s->trgt.where = s->trgt.tmp_where;
			s->trgt.moves = s->trgt.tmp_moves;
		}
	}
	else if (stk == 'b')
	{
		if (s->trgt.tmp_where == 0 || s->trgt.tmp_moves < s->trgt.moves)
		{
			s->trgt.which = s->trgt.tmp_which;
			s->trgt.where = s->trgt.tmp_where;
			s->trgt.moves = s->trgt.tmp_moves;
		}
	}
}

void	count_moves_a(t_stack *s)
{
	find_half(s, 'a');
	find_half(s, 'b');
	if (s->trgt.tmp_which < s->half.half_a
		&& s->trgt.tmp_where < s->half.half_b)
		upper_half(s);
	else if (s->trgt.tmp_which >= s->half.half_a
		&& s->trgt.tmp_where >= s->half.half_b)
		lower_half(s);
	else
		one_up_one_down(s);
	move(s, 'a');
}

void	count_moves_b(t_stack *s)
{
	find_half(s, 'a');
	find_half(s, 'b');
	if (s->trgt.tmp_which < s->half.half_a
		&& s->trgt.tmp_where < s->half.half_b)
		upper_half(s);
	else if (s->trgt.tmp_which >= s->half.half_a
		&& s->trgt.tmp_where >= s->half.half_b)
		lower_half(s);
	else
		one_up_one_down(s);
	move(s, 'b');
}
