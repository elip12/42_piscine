# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epandolf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/17 14:22:51 by epandolf          #+#    #+#              #
#    Updated: 2017/07/17 14:22:53 by epandolf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = bsq.c ft_split_whitespaces.c ft_atoi.c malloc.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:

fclean:
	/bin/rm -f $(NAME)

re: fclean all
