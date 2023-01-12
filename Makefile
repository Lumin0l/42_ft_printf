# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:41:12 by ide-la-i          #+#    #+#              #
#    Updated: 2023/01/12 18:04:14 by ide-la-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = ft_printf.c\

		ft_aux.c

OBJS = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)

	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SOURCE)

	gcc -Wall -Wextra -Werror -c $(SOURCE)

clean:

	rm -f $(OBJS)

fclean : clean

	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re