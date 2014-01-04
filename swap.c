/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 22:28:22 by gbir              #+#    #+#             */
/*   Updated: 2013/12/29 18:04:42 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void		ft_swap(t_sort **a)
{
	int		tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = tmp;
	}
}

void		ft_dswap(t_sort **a, t_sort **b)
{
	ft_swap(a);
	ft_swap(b);
}
