/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <ldi-fior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:18:09 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/02/28 14:27:45 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_up(t_stack *s)
{
	while (s->trgt.which != 0 && s->trgt.where != 0)
	{
		rr(s);
		s->trgt.which--;
		s->trgt.where--;
	}
	while (s->trgt.which != 0)
	{
		ra(s);
		s->trgt.which--;
	}
	while (s->trgt.where != 0)
	{
		rb(s);
		s->trgt.where--;
	}
}

void	up_down(t_stack *s)
{
	while (s->trgt.which != 0)
	{
		ra(s);
		s->trgt.which--;
	}
	while (s->trgt.where < s->len_b)
	{
		rrb(s);
		s->trgt.where++;
	}
}

void	down_up(t_stack *s)
{
	while (s->trgt.which < s->len_a)
	{
		rra(s);
		s->trgt.which++;
	}
	while (s->trgt.where != 0)
	{
		rb(s);
		s->trgt.where--;
	}
}

void	both_down(t_stack *s)
{
	int	i;

	i = -1;
	if (s->len_a - s->trgt.which > s->len_b - s->trgt.where)
	{
		while (++i < (s->len_b - s->trgt.where))
			rrr(s);
		i = -1;
		while (++i < (s->len_a - s->trgt.which) - (s->len_b - s->trgt.where))
			rra(s);
	}
	else
	{
		i = -1;
		while (++i < (s->len_a - s->trgt.which))
			rrr(s);
		i = -1;
		while (++i < (s->len_b - s->trgt.where) - (s->len_a - s->trgt.which))
			rrb(s);
	}
}

void	sort_and_push(t_stack *s, char str)
{
	if (s->trgt.which < s->half.half_a && s->trgt.where < s->half.half_b)
		both_up(s);
	else if (s->trgt.which < s->half.half_a && s->trgt.where >= s->half.half_b)
		up_down(s);
	else if (s->trgt.which >= s->half.half_a && s->trgt.where < s->half.half_b)
		down_up(s);
	else if (s->trgt.which >= s->half.half_a && s->trgt.where >= s->half.half_b)
		both_down(s);
	if (str == 'a')
		pb(s);
	else
		pa(s);
}
