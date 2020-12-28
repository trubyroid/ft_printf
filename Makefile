# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truby <truby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 21:53:13 by truby             #+#    #+#              #
#    Updated: 2020/12/27 20:31:28 by truby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FILES = ft_calloc_char.c ft_char_type.c ft_hex.c ft_int_type.c ft_parse_flag.c\
ft_parse_precision.c ft_parse_type.c ft_parse_width.c ft_parser_var.c ft_pointer_type.c\
ft_printf.c ft_processor.c ft_str_type.c ft_un_int_type.c ft_xx_type.c\
ft_percent_type.c

O_FILES = $(C_FILES:.c=.o)

HEADER = printf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	make -C ./libft
	ar -rcs $(NAME) $(O_FILES) ./libft/*.o

%.o: %.c $(HEADER)
	gcc -Wall -Wextra -Werror -c $<

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all