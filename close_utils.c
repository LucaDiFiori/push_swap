/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <ldi-fior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:46:27 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/02/29 16:38:41 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_matrix(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
	return (0);
}

int	quit_and_free(t_stack *stk, int error)
{
	if (error == 0)
		write(2, "Error\n", 6);
	else if (error == 1)
	{
		write(2, "Error\n", 6);
		free(stk->stk_a);
		free(stk->stk_b);
	}
	exit (0);
}
