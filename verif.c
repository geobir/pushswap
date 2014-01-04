/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:54:42 by gbir              #+#    #+#             */
/*   Updated: 2013/12/29 23:16:41 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include <unistd.h>
#include <stdlib.h>

static void		ft_apply(char *s, t_sort **a, t_sort **b)
{
	while (*s)
	{
		if (*s == 1)
			ft_swap(a);
		else if (*s == 2)
			ft_swap(b);
		else if (*s == 3)
			ft_dswap(a, b);
		else if (*s == 4)
			ft_permut(b, a);
		else if (*s == 5)
			ft_permut(a, b);
		else if (*s == 6)
			ft_rotate(a);
		else if (*s == 7)
			ft_rotate(b);
		else if (*s == 8)
			ft_drotate(a, b);
		else if (*s == 9 || *s == 11)
			ft_rrotate(a);
		else if (*s == 10 || *s == 11)
			ft_rrotate(b);
		++s;
	}
}

static t_sort	**sortdup(t_sort **a)
{
	t_sort	*cur;
	t_sort	*s;
	t_sort	*sav;
	t_sort	**ret;

	s = *a;
	if (!(ret = (t_sort**)malloc(sizeof(t_sort*) * 2)) && (ERROR))
		exit(0);
	ret[0] = NULL;
	while (s)
	{
		if (!(cur = (t_sort*)malloc(sizeof(t_sort))) && (ERROR))
			exit(0);
		cur->num = s->num;
		if (!ret[0])
			ret[0] = cur;
		else if ((sav->next = cur))
			cur->prev = sav;
		sav = cur;
		s = s->next;
	}
	ret[1] = cur;
	cur->next = NULL;
	return (ret);
}

static char		ft_sfree(t_sort **a, t_sort **b)
{
	t_sort	*tmp;

	while (*a)
	{
		tmp = *a;
		free(tmp);
		*a = (*a)->next;
	}
	free(a);
	while (*b)
	{
		tmp = *b;
		free(tmp);
		*b = (*b)->next;
	}
	free(b);
	return (1);
}

static int		ft_pretest(char *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == 4)
			++i;
		else if (*s == 5)
			--i;
		else if (i < 0 && (*s == 2 || *s == 4 || *s == 7 || *s == 10 \
					  || *s == 8 || *s == 11 || *s == 3))
			return (0);
		++s;
	}
	if (!i)
		return (1);
	return (0);
}

int				ft_verif(t_sort **a, char *s)
{
	t_sort	**s_a;
	t_sort	**s_b;
	int		tmp;
	t_sort	*t_a;

	if (s && !ft_pretest(s))
		return (0);
	if (!(s_b = (t_sort**)malloc(sizeof(t_sort*) * 2)) && (ERROR))
		exit(0);
	if ((s_a = sortdup(a)) && !(*s_b = NULL) && s)
		ft_apply(s, s_a, s_b);
	if ((tmp = (*s_a)->num) && !(t_a = *s_a) && (ft_sfree(s_a, s_b)))
		return (0);
	if (*s_b && (ft_sfree(s_a, s_b)))
		return (0);
	while (t_a)
	{
		if (t_a->num < tmp && (ft_sfree(s_a, s_b)))
			return (0);
		tmp = t_a->num;
		t_a = t_a->next;
	}
	ft_printresult(s);
	exit(0);
	return (1);
}
