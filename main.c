/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 21:47:01 by gbir              #+#    #+#             */
/*   Updated: 2013/12/29 22:06:26 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include <unistd.h>
#include <stdlib.h>

static t_sort	**ft_malsort(int ac, char **av)
{
	t_sort		**ret;
	t_sort		*sav;
	t_sort		*cur;

	if (!(ret = (t_sort**)malloc(sizeof(t_sort*) * 2)) && (ERROR))
		exit(0);
	ret[0] = NULL;
	while (--ac)
	{
		if (!(cur = (t_sort*)malloc(sizeof(t_sort))) && (ERROR))
			exit(0);
		cur->num = ft_atoi(*(++av));
		if (!ret[0])
			ret[0] = cur;
		else
		{
			sav->next = cur;
			cur->prev = sav;
		}
		sav = cur;
	}
	ret[1] = cur;
	return (&(ret[0]));
}

void			ft_printresult(char *s)
{
	char	*cur;
	char	*str[12] = {" ", "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr" \
						, "rra", "rrb", "rrr"};

	if (s)
	{
		while (42)
		{
			cur = str[((int)*s)];
			write(1, cur, ft_strlen(cur));
			if (*(++s))
				write(1, " ", 1);
			else
				break ;
		}
	}
	write(1, "\n", 1);
}

int				main(int ac, char **av)
{
	t_sort	**s_a;

	if (ac > 1)
	{
		s_a = ft_malsort(ac, av);
		ft_pars(s_a, ac - 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
