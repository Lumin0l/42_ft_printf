# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 12:41:12 by ide-la-i          #+#    #+#              #
#    Updated: 2023/01/20 13:33:17 by ide-la-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c ft_aux.c 

OBJ = $(SOURCE:.c=.o)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SOURCE)
	@$(LIB) $(OBJ)
	@$(RANLIB) $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re