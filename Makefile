# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:27:57 by gchernys          #+#    #+#              #
#    Updated: 2023/02/21 14:13:47 by muganiev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= minishell
CC 					= gcc -g
FLAGS 				= -Wall -Werror -Wextra
INCLUDES 			= -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) \
						-I$(FT_PRINTF_HEADERS) -I/usr/local/opt/readline/include
LIBRARIES 			= -lft -lft_printf \
						-L$(LIBFT_DIRECTORY) -L$(FT_PRINTF_DIRECTORY) \
						-L/usr/local/opt/readline/lib

LIB_DIRECTORY 		= ./lib/

LIBFT 				= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY 	= $(LIB_DIRECTORY)libft/
LIBFT_HEADERS 		= $(LIBFT_DIRECTORY)includes/

FT_PRINTF			= $(FT_PRINTF_DIRECTORY)libft_printf.a
FT_PRINTF_DIRECTORY = $(LIB_DIRECTORY)ft_printf/
FT_PRINTF_HEADERS 	= $(FT_PRINTF_DIRECTORY)includes/

HEADERS_DIRECTORY 	= ./includes/
HEADERS_LIST 		= minishell.h
HEADERS 			= $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY 	= ./sources/
SOURCES_LIST 		= main.c sh_debug.c sh_env.c sh_keymap.c sorting_list.c sh_signals.c \
						utils/str_utils.c \
						utils/str_utils2.c \
						utils/list_utils.c \
						utils/env_utils.c \
						utils/utils.c \
						utils/signal_utils.c \
						builtins/cmd_cd.c \
						builtins/cmd_echo.c \
						builtins/cmd_env.c \
						builtins/cmd_exit.c \
						builtins/cmd_export.c \
						builtins/cmd_pwd.c \
						builtins/cmd_unset.c \
						builtins/cmd_execve.c \
						parsing/sh_parsing.c \
						parsing/sh_exec.c \
						parsing/exec_utils.c \
						parsing/sh_pipe.c \
						parsing/block.c \
						parsing/sh_quote.c \
						parsing/redir_utils.c \
						parsing/sh_redir.c \
						parsing/sh_tokens.c \
						parsing/sh_expansion.c \
						exec/executor.c \
						exec/ex_utils.c \
						exec/ex_utils2.c
						
SOURCES 			= $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY 	= objects/
OBJECTS_LIST 		= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS				= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS
GREEN 				= \033[0;32m
YELLOW 				= \033[1;33m
RED					= \033[0;31m
RESET 				= \033[0m

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBRARIES) $(INCLUDES) -lreadline -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)/parsing
	@mkdir -p $(OBJECTS_DIRECTORY)/exec
	@mkdir -p $(OBJECTS_DIRECTORY)/builtins
	@mkdir -p $(OBJECTS_DIRECTORY)/utils
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo ".\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(FT_PRINTF):
	@echo "$(NAME): $(GREEN)Creating $(FT_PRINTF)...$(RESET)"
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(FT_PRINTF)
	@echo "$(NAME): $(RED)$(FT_PRINTF) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus clean fclean re