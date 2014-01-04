/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 00:53:39 by gbir              #+#    #+#             */
/*   Updated: 2013/12/29 18:06:05 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void		ft_permut(t_sort **a, t_sort **b)
{
	t_sort	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		if (*b)
		{
			(*a)->next = *b;
			(*b)->prev = *a;
		}
		else
		{
			(*a)->next = 0;
			b[1] = *a;
		}
		*b = *a;
		if (tmp)
		{
			*a = tmp;
			(*a)->prev = 0;
		}
		else if (!(*a = 0))
			a[1] = 0;
	}
}