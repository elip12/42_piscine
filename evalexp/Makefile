# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epandolf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/15 22:18:01 by epandolf          #+#    #+#              #
#    Updated: 2017/07/15 22:18:02 by epandolf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) eval_expr.c deque.c ft_atoi.c helper_fcns.c helper_fcns2.c

clean:
	/bin/rm -f

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean clean re

