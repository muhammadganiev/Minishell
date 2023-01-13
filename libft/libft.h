/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:31:56 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/14 22:47:49 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}				t_lst;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int			ft_atoi(const char *str);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t smthn, size_t size);

int			ft_isalnum(int a);

int			ft_isalpha(int a);

int			ft_isascii(int a);

int			ft_isdigit(int a);

int			ft_isprint(int a);

char		*ft_itoa(int n);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstadd_front(t_list **lst, t_list *new);

void		ft_lstclear(t_list **lst, void (*del)(void*));

void		ft_lstdelone(t_list *lst, void (*del)(void *));

void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstlast(t_list *lst);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list		*ft_lstnew(void *content);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

int			ft_lstsize(t_list *lst);

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memmove(void *dest, const void *src, size_t n);

void		*ft_memcpy(void *dest, const void *src, size_t n);

void		*ft_memset(void *b, int c, size_t len);

void		ft_putchar_fd(char c, int fd);

int			ft_strcmp(char *s1, char *s2);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

void		ft_putstr_fd(char *s, int fd);

char		**ft_split(char const *s, char c);

char		*ft_strchr(const char *s, int c);

char		*ft_strdup(const char *str);

void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		*ft_strjoin(char *s1, char *s2);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

int			ft_strlen(const char *str);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int			ft_strncmp(const char *s1, const char *s2, int n);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

char		*ft_strrchr(const char *str, int c);

char		*ft_strtrim(char const *s1, char const *set);

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_tolower(int a);

int			ft_toupper(int a);

void		ft_putnbr(int i);

int			ft_putchar(int c);

void		ft_putstr(char *s);

char		*ft_strncpy(char *dest, const char *src, size_t n);

int			ft_strlen_gnl(char *s);

int			ft_strchr_gnl(char *str, int *i, int *give_loc);

char		*ft_strjoin_gnl(char *s1, char *s2);

char		*fill_buf(char *buf, int loc);

char		*create_result(char *buf, int loc);

char		*ft_read(int fd, char *buf, int *loc);

char		*get_next_line(int fd);

int			ft_putcharc(int c);
int			ft_putstrs(char *str);
int			ft_printf(const char *str, ...);
int			ft_switcher(va_list args, const char let);
int			ft_printperc(void);
int			ft_hexax(unsigned long long int i, int len);
void		ft_putchar_fd(char c, int fd);
int			ft_putpointer(unsigned long n);
int			print_hex(va_list args, char c);
int			print_pointer(va_list args);
void		ft_putstr_fd(char *s, int fd);
int			ft_printunsigned(va_list args);
int			ft_printint(va_list args);
int			ft_unsignednbr(unsigned int i);
int			ft_putnbrprintf(int i);

int			ft_isspace(int c);

#endif