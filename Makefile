#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/25 21:41:29 by gbir              #+#    #+#              #
#    Updated: 2013/12/29 03:22:03 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	push_swap
CC		=	cc
SRCS	=	main.c			ft_atoi.c		rrotate.c	\
			permut.c		swap.c			rotate.c	\
			algo.c			ft_strlen.c		verif.c

OBJ		=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra -O3 -g

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

$(OBJ):		$(SRCS)
			$(CC) -c $(CFLAGS) $(SRCS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
