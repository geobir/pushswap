/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 21:49:53 by gbir              #+#    #+#             */
/*   Updated: 2013/12/29 22:54:55 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H
# define ERROR write(2, "Error\n", 7)
# include <stddef.h>

typedef struct		s_sort
{
	int				num;
	struct s_sort	*next;
	struct s_sort	*prev;
}					t_sort;

typedef struct		s_arg
{
	size_t	lvl;
	t_sort	**a;
}					t_arg;

int		ft_atoi(const char *str);
void	ft_swap(t_sort **a);
void	ft_dswap(t_sort **a, t_sort **b);
void	ft_permut(t_sort **a, t_sort **b);
void	ft_rotate(t_sort **a);
void	ft_drotate(t_sort **a, t_sort **b);
void	ft_rrotate(t_sort **a);
void	ft_pars(t_sort **a, int i);
int		ft_strlen(const char *s);
int		ft_verif(t_sort **a, char *s);
void	ft_printresult(char *s);

#endif
