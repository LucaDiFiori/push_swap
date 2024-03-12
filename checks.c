/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <ldi-fior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:24:03 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/02/29 18:00:36 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int	ch_nbr(char	*str, int argc)
{
	int	i;

	i = 0;
	if (argc == 2 && (str[0] == '-' || str[0] == '+'))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		if (!(ft_strncmp(str, "-2147483650"))
			|| !(ft_strncmp(str, "2147483648"))
			|| !(ft_strncmp(str, "-2147483649"))
			|| !(ft_strncmp(str, "2147483649")))
			return (0);
		i++;
	}
	if (((str[0] == '-' || str[0] == '+') && i > 11)
		|| ((str[0] >= '0' && str[0] <= '9') && i > 10))
		return (0);
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	int		count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		tmp = ft_split(argv[i], 32);
		if (!tmp)
			return (0);
		j = -1;
		while (tmp[++j])
		{
			if (!ch_nbr(tmp[j], argc))
				return (free_matrix(tmp));
			count++;
		}
		free_matrix(tmp);
	}
	return (count);
}

int	ch_double(t_stack *stk)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stk->len_a - 1)
	{
		j = i + 1;
		while (j < stk->len_a && stk->stk_a[i] != stk->stk_a[j])
			j++;
		if (j < stk->len_a)
			return (0);
		i++;
	}
	return (1);
}
