/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 01:13:54 by gbir              #+#    #+#             */
/*   Updated: 2013/12/29 22:34:52 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void		ft_rotate(t_sort **a)
{
	t_sort	*tmp;

	if (*a && *a != a[1])
	{
		tmp = (*a)->next;
		a[1]->next = *a;
		(*a)->prev = a[1];
		a[1] = *a;
		(*a)->next = 0;
		*a = tmp;
		(*a)->prev = 0;
	}
}

void		ft_drotate(t_sort **a, t_sort **b)
{
	t_sort	*tmp;

	if (*a && *a != a[1])
	{
		tmp = (*a)->next;
		a[1]->next = *a;
		(*a)->prev = a[1];
		a[1] = *a;
		(*a)->next = 0;
		*a = tmp;
		(*a)->prev = 0;
	}
	if (*b && *b != b[1])
	{
		tmp = (*b)->next;
		b[1]->next = *b;
		(*b)->prev = b[1];
		b[1] = *b;
		(*b)->next = 0;
		*b = tmp;
		(*b)->prev = 0;
	}
}
