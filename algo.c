/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:38:39 by gbir              #+#    #+#             */
/*   Updated: 2013/12/29 22:30:44 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Ordre de tris:
** SA = 1 | SB = 2 | SS  = 3 | PA  =  4 | PB  =  5 | RA = 6 |
** RB = 7 | RR = 8 | RRA = 9 | RRB = 10 | RRR = 11
*/
static void		ft_stack(char *s, t_arg *a, size_t cur, char l)
{
	if (++s && cur >= a->lvl && !(ft_verif(a->a, s - a->lvl)))
		return ;
	if (l != 1 && l != 2 && l != 3 && (*s = 1))
		ft_stack(s, a, cur + 1, 1);
	if (l != 1 && l != 2 && l != 3 && (*s = 2))
		ft_stack(s, a, cur + 1, 2);
	if (l != 1 && l != 2 && l != 3 && (*s = 3))
		ft_stack(s, a, cur + 1, 3);
	if (l != 5 && (*s = 4))
		ft_stack(s, a, cur + 1, 4);
	if (l != 4 && (*s = 5))
		ft_stack(s, a, cur + 1, 5);
	if (l != 9 && l != 7 && l != 8 && l != 11 && (*s = 6))
		ft_stack(s, a, cur + 1, 6);
	if (l != 10 && l != 6 && l != 8 && l != 11 && (*s = 7))
		ft_stack(s, a, cur + 1, 7);
	if (l != 6 && l != 7 && l != 11 && (*s = 8))
		ft_stack(s, a, cur + 1, 8);
	if (l != 6 && l != 10 && l != 8 && l != 11 && (*s = 9))
		ft_stack(s, a, cur + 1, 9);
	if (l != 7 && l != 9 && l != 8 && l != 11 && (*s = 10))
		ft_stack(s, a, cur + 1, 10);
	if (l != 9 && l != 10 && l != 8 && (*s = 11))
		ft_stack(s, a, cur + 1, 11);
}

static char		*ft_inimalloc(size_t i)
{
	char	*way;
	char	*ini;

	way = malloc(i);
	ini = way;
	while (i--)
		*ini++ = 0;
	return (way);
}

/*
** parseur
*/
void			ft_pars(t_sort **a, int i)
{
	t_arg		*arg;
	char		*dom;

	i = 0;
	ft_verif(a, NULL);
	arg = malloc(sizeof(t_arg));
	arg->lvl = 1;
	arg->a = a;
	while (42)
	{
		dom = ft_inimalloc(arg->lvl + 2);
		ft_stack(dom, arg, 0, 0);
		free(dom);
		arg->lvl += 1;
	}
}
