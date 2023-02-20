/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:36:58 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:37:01 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

struct s_data
{
	int	precision;
	int	width;
	int	is_precision;
	int	is_left_justify;
	int	is_positive_sign;
	int	is_hash;
	int	is_zero;
	int	is_space;
};

int				ft_fprintf(int fd, const char *str, ...);
int				ft_printf(const char *str, ...);
struct s_data	ft_parse_flags(const char **flag);
int				pf_putlchar_fd(char c, int fd, struct s_data data);
int				pf_putlstr_fd(char *str, int fd, struct s_data data);
int				pf_putlnbr_fd(int nbr, int fd, struct s_data data);
int				pf_putlunbr_fd(unsigned int nbr, int fd, struct s_data data);
int				pf_putlhex_fd(unsigned int n, int f, int u, struct s_data d);
int				pf_putlptr_fd(unsigned long long p, int f, struct s_data d);
int				pf_width(int n, int is_zero, int fd);
int				ft_digitlen(int long long nbr);
void			ft_puthex(unsigned long long num, int fd, int isupper);
int				ft_hexlen(unsigned long long num);

#endif