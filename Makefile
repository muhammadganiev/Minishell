# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:27:57 by gchernys          #+#    #+#              #
#    Updated: 2023/02/17 08:07:14 by gchernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell 

AR = ar rcs

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -L/usr/include/ -I/usr/local/Cellar/readline/8.1/include

LIBFT = cd libft && make

CLEANLIB = cd libft && make clean

FCLEANLIB = cd libft && make fclean

FILES =	./main.c								\
		./src/sh_env.c							\
		./src/sh_keymap.c						\
		./src/sh_signals.c						\
		./src/sorting_list.c					\
		./src/utils/env_utils.c 				\
		./src/utils/shell_utils.c 				\
		./src/utils/signal_utils.c				\
		./src/utils/str_utils.c 				\
		./src/utils/str_utils2.c 				\
		./src/parsing/redirection_extra.c 		\
		./src/parsing/redirections.c 			\
		./src/parsing/sh_exec.c					\
		./src/parsing/sh_expansion.c			\
		./src/parsing/sh_pipes_parsing.c		\
		./src/parsing/sh_parsing.c				\
		./src/parsing/sh_quotes.c				\
		./src/parsing/exec_arg.c				\
		./src/parsing/sh_tokens.c				\
		./src/exec/ex_utils_more.c				\
		./src/exec/ex_utils.c					\
		./src/exec/executor.c					\
		./src/builtins/cmd_cd.c					\
		./src/builtins/cmd_echo.c				\
		./src/builtins/cmd_env.c				\
		./src/builtins/cmd_execve.c				\
		./src/builtins/cmd_exit.c				\
		./src/builtins/cmd_export.c				\
		./src/builtins/cmd_unset.c
		
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
	cd src/utils && rm -rf *.o
	cd src/parsing && rm -rf *.o
	$(CLEANLIB)

fclean: clean
	$(RM) $(NAME)
	$(FCLEANLIB)

re: fclean all

.PHONY:	all clean fclean re