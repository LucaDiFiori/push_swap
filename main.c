/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <ldi-fior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:15 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/02/29 16:39:37 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stk;
	int		n_arg;

	if (argc < 2)
		exit (0);
	n_arg = check_arg(argc, argv);
	if (n_arg <= 1)
	{
		if (!n_arg)
			write(2, "Error\n", 6);
		exit (1);
	}
	push_swap(&stk, n_arg, argc, argv);
	free (stk.stk_a);
	free (stk.stk_b);
}
