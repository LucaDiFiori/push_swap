/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <ldi-fior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:41:17 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/02/28 14:10:04 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rot(int	*stk, int len)
{
	int	i;
	int	tmp;

	i = len - 1;
	tmp = stk[i];
	while (i > 0)
	{
		stk[i] = stk[i - 1];
		i--;
	}
	if (i == 0)
		stk[i] = tmp;
}

void	rra(t_stack *stk)
{
	rev_rot(stk->stk_a, stk->len_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stk)
{
	rev_rot(stk->stk_b, stk->len_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stk)
{
	rev_rot(stk->stk_a, stk->len_a);
	rev_rot(stk->stk_b, stk->len_b);
	ft_printf("rrr\n");
}
