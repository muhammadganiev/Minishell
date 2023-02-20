/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:37:58 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:37:59 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	parse_printf(va_list ap, const char **f, int fd)
{
	int					len;
	struct s_data		data;

	data = ft_parse_flags(f);
	len = 0;
	if (**f == 'c')
		len = pf_putlchar_fd(va_arg(ap, int), fd, data);
	else if (**f == 's')
		len = pf_putlstr_fd(va_arg(ap, char *), fd, data);
	else if (**f == 'p')
		len += pf_putlptr_fd(va_arg(ap, unsigned long long), fd, data);
	else if (**f == 'd' || **f == 'i')
		len = pf_putlnbr_fd(va_arg(ap, int), fd, data);
	else if (**f == 'u')
		len = pf_putlunbr_fd(va_arg(ap, int), fd, data);
	else if (**f == 'x' || **f == 'X')
		len = pf_putlhex_fd(va_arg(ap, unsigned int), fd, **f == 'X', data);
	else if (**f == '%')
		len = pf_putlchar_fd('%', fd, data);
	return (len);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += parse_printf(ap, &str, fd);
		}
		else
			len += write(fd, str, 1);
		str++;
	}
	va_end(ap);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += parse_printf(ap, &str, 1);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (len);
}
