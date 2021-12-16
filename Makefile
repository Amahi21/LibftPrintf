# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amahi <amahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 13:05:38 by amahi             #+#    #+#              #
#    Updated: 2021/12/07 16:17:23 by amahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST =	ft_printf.c			\
		ft_printf_utils.c	

OBJ = $(patsubst %.c, %.o,  $(LIST))

HEADER = ft_printf.h

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) $(LIST)
	ar rcs $(NAME)

%.o : %.c $(HEADER)
	gcc $(FLAGS) -c $< -o -MD

clean : 
	rm -f $(OBJ)
	rm -f *.d

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re