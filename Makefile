# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:27:57 by gchernys          #+#    #+#              #
#    Updated: 2023/02/01 21:41:56 by gchernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell 

AR = ar rcs

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -L /usr/include/readline/readline.h -I /usr/local/Cellar/readline/8.1/include

LIBFT = cd libft && make

CLEANLIB = cd libft && make clean

FCLEANLIB = cd libft && make fclean

FILES =	./main.c	\
		./src/sh_env.c	\
		./src/sh_keymap.c	\
		./src/sh_signals.c	\
		./src/utils/shell_utils.c	\
		./src/utils/str_utils.c
		
FILES_O = $(FILES:.c=.o)

all: $(NAME)

$(NAME)	:	$(FILES_O)
			$(LIBFT)
			$(CC) $(CFLAGS) $(FILES_O) -o minishell

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	cd src && rm -rf *.o
	$(CLEANLIB)

fclean: clean
	$(RM) $(NAME)
	$(FCLEANLIB)

re: fclean all

.PHONY:	all clean fclean re