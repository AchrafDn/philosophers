# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adadoun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 03:17:52 by adadoun           #+#    #+#              #
#    Updated: 2023/07/26 03:17:54 by adadoun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
Cflags = -Wall -Wextra -Werror
Cfiles = ft_atoi.c \
		main.c \
		ft_utils1.c \
		ft_utils2.c

OBJ = ${Cfiles:.c=.o}

RM = rm -f
NAME = philo

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(Cflags) $(OBJ) -o $(NAME)

.c.o:
		$(CC) $(Cflags) -c $< -o $@

clean :
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
