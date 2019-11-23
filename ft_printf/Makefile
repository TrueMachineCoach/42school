# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#              #
#    Updated: 2019/11/23 17:23:20 by gtapioca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB =  libftprintf.a
LIBFT = libft/libft.a
SRC =	display_f.c\
		print_date.c\
		print_non_printable.c\
		resolve_diouxx.c\
		resolve_diouxx2.c\
		parse.c\
		parse_2.c\
		handle_data.c\
		print_inf_nan.c\
		print_inf_nan2.c\
		print_pointer.c\
		print_char_str.c\
		print_binary.c\
		field_formatt_resolver.c\
		field_formatt_resolver_1.c\
		field_formatt_resolver_2.c\
		field_formatt_resolver_3.c\
		field_formatt_resolver_4.c\
		field_formatt_resolver_5.c\
		field_formatt_resolver_6.c\
		field_formatt_resolver_7.c\
		field_formatt_resolver_8.c\
		field_formatt_resolver_9.c\
		field_formatt_resolver_10.c\
		field_formatt_resolver_11.c\
		print_%%.c\
		main.c\
		
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror		
		
.PHONY: all fclean clean re

all: $(NAME_LIB)

%.o:%.c
	gcc $(FLAGS) -c $(SRC)

$(NAME_LIB): $(OBJ)
	libtool -static -o $(NAME_LIB) $(OBJ) $(LIBFT)
	ranlib $(NAME_LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME_LIB)

re: fclean all