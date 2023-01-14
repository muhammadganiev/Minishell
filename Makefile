# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:27:57 by gchernys          #+#    #+#              #
#    Updated: 2023/01/14 20:49:00 by muganiev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell 

AR = ar rcs

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -L /usr/local/Cellar/readline/8.1/lib -I /usr/local/Cellar/readline/8.1/include

LIBFT = cd libft && make

CLEANLIB = cd libft && make clean

FCLEANLIB = cd libft && make fclean

FILES =	./main.c	\
		./src/sh_parsing.c	\
		./src/sh_lexer.c
		
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