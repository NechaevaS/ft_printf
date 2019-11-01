# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 14:47:44 by snechaev          #+#    #+#              #
#    Updated: 2019/10/31 17:31:52 by snechaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS =ft_printf.o\
			parsing.o\
			format_utils.o\
			print_str.o\
			libft/libft.a\


CFLAGS = -Wall -Wextra -Werror -g -O0 

all : $(NAME)

$(NAME) : $(OBJS) lib
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJS) : ft_printf.h

lib:
	@make -C libft

clean :
	rm -f $(OBJS)
	@make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
