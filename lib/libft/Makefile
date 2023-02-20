# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 02:48:11 by gchernys          #+#    #+#              #
#    Updated: 2023/02/20 16:27:51 by muganiev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES =	./includes/../includes/libft.h

SRC_PART1 =	./sources/ft_memset.c	\
			./sources/ft_bzero.c	\
			./sources/ft_memcpy.c	\
			./sources/ft_memmove.c	\
			./sources/ft_memchr.c	\
			./sources/ft_memcmp.c	\
			./sources/ft_calloc.c	\
			./sources/ft_strlen.c	\
			./sources/ft_strlcpy.c	\
			./sources/ft_strlcat.c	\
			./sources/ft_strchr.c	\
			./sources/ft_strrchr.c	\
			./sources/ft_strncmp.c	\
			./sources/ft_strnstr.c	\
			./sources/ft_strdup.c	\
			./sources/ft_isdigit.c	\
			./sources/ft_atoi.c		\
			./sources/ft_isalpha.c	\
			./sources/ft_isalnum.c	\
			./sources/ft_isascii.c	\
			./sources/ft_isprint.c	\
			./sources/ft_toupper.c	\
			./sources/ft_striteri.c	\
			./sources/ft_tolower.c	\
			./sources/ft_putnbr.c	\
			./sources/ft_putchar.c	\
			./sources/ft_putstr.c	\
			./sources/ft_strncpy.c	\
			./sources/get_next_line.c	\
			./sources/get_next_line_utils.c	\
			./sources/ft_printf.c	\
			./sources/ft_hexax.c	\
			./sources/ft_basetendi.c	\
			./sources/ft_printperc.c	\
			./sources/ft_putcharc.c		\
			./sources/ft_putstrs.c		\
			./sources/ft_strcmp.c		\
			./sources/ft_isspace.c
	
SRC_PART2 =	./sources/ft_substr.c	\
			./sources/ft_strjoin.c	\
			./sources/ft_strtrim.c	\
			./sources/ft_split.c	\
			./sources/ft_itoa.c		\
			./sources/ft_strmapi.c	\
			./sources/ft_putchar_fd.c	\
			./sources/ft_putstr_fd.c	\
			./sources/ft_putendl_fd.c	\
			./sources/ft_putnbr_fd.c

SRCS = 	$(SRC_PART1)	\
	$(SRC_PART2)
	
OBJS = $(SRCS:.c=.o)

SRC_BONUS =	./sources/ft_lstnew.c	\
			./sources/ft_lstadd_front.c	\
			./sources/ft_lstsize.c	\
			./sources/ft_lstlast.c	\
			./sources/ft_lstadd_back.c	\
			./sources/ft_lstdelone.c	\
			./sources/ft_lstclear.c	\
			./sources/ft_lstiter.c	\
			./sources/ft_lstmap.c

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.c.o : $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY: all clean fclean re