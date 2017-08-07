# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makeprintf                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meassas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/24 15:06:11 by meassas           #+#    #+#              #
#    Updated: 2017/08/03 17:08:44 by meassas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

SRC = 	add_width_with_space_or_zero.c\
		check_flags.c\
		check_length.c\
		check_precision.c\
		check_specifier.c\
		check_width.c\
		ft_printf_int.c\
		printf_hex.c\
		handle_length.c\
		printf_octal.c\
		printf_pointer.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

$(OBJ) : $(SRC)
	@gcc -c $(FLAGS) $(SRC)

clean :
		@/bin/rm -f $(OBJ)

fclean : clean
		@/bin/rm -f $(NAME)

re : fclean all
