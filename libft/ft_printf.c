/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:18:55 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/15 15:13:40 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_switcher(va_list args, const char let)
{
	int	i;

	i = 0;
	if (let == 'c')
		i += ft_putcharc(va_arg(args, int));
	else if (let == 's')
		i += ft_putstrs(va_arg(args, char *));
	else if (let == '%')
		i += ft_printperc();
	else if (let == 'x' || let == 'X')
		i += print_hex(args, let);
	else if (let == 'p')
		i += print_pointer(args);
	else if (let == 'd' || let == 'i')
		i += ft_printint(args);
	else if (let == 'u')
		i += ft_printunsigned(args);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		cnt;

	cnt = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			cnt += ft_switcher(args, str[i + 1]);
			i++;
		}
		else
			cnt += ft_putcharc(str[i]);
		i++;
	}
	va_end(args);
	return (cnt);
}
