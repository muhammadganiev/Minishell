# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 02:48:11 by gchernys          #+#    #+#              #
#    Updated: 2022/07/14 22:47:33 by gchernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES =	./libft.h

SRC_PART1 =	./ft_memset.c	\
			./ft_bzero.c	\
			./ft_memcpy.c	\
			./ft_memmove.c	\
			./ft_memchr.c	\
			./ft_memcmp.c	\
			./ft_calloc.c	\
			./ft_strlen.c	\
			./ft_strlcpy.c	\
			./ft_strlcat.c	\
			./ft_strchr.c	\
			./ft_strrchr.c	\
			./ft_strncmp.c	\
			./ft_strnstr.c	\
			./ft_strdup.c	\
			./ft_isdigit.c	\
			./ft_atoi.c		\
			./ft_isalpha.c	\
			./ft_isalnum.c	\
			./ft_isascii.c	\
			./ft_isprint.c	\
			./ft_toupper.c	\
			./ft_striteri.c	\
			./ft_tolower.c	\
			./ft_putnbr.c	\
			./ft_putchar.c	\
			./ft_putstr.c	\
			./ft_strncpy.c	\
			./get_next_line.c	\
			./get_next_line_utils.c	\
			./ft_printf.c	\
			./ft_hexax.c	\
			./ft_basetendi.c	\
			./ft_printperc.c	\
			./ft_putcharc.c		\
			./ft_putstrs.c		\
			./ft_strcmp.c		\
			./ft_isspace.c
	
SRC_PART2 =	./ft_substr.c	\
			./ft_strjoin.c	\
			./ft_strtrim.c	\
			./ft_split.c	\
			./ft_itoa.c		\
			./ft_strmapi.c	\
			./ft_putchar_fd.c	\
			./ft_putstr_fd.c	\
			./ft_putendl_fd.c	\
			./ft_putnbr_fd.c

SRCS = 	$(SRC_PART1)	\
	$(SRC_PART2)
	
OBJS = $(SRCS:.c=.o)

SRC_BONUS =	./ft_lstnew.c	\
			./ft_lstadd_front.c	\
			./ft_lstsize.c	\
			./ft_lstlast.c	\
			./ft_lstadd_back.c	\
			./ft_lstdelone.c	\
			./ft_lstclear.c	\
			./ft_lstiter.c	\
			./ft_lstmap.c

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