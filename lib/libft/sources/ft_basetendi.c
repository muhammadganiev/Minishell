/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetendi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:19:14 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:51 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbrprintf(int i)
{
	int	count;

	count = 1;
	if (i == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		i = -i;
	}
	if (i > 9)
		count += ft_putnbrprintf(i / 10);
	ft_putchar_fd(i % 10 + '0', 1);
	return (count);
}

int	ft_unsignednbr(unsigned int i)
{
	int	count;

	count = 1;
	if (i > 9)
		count += ft_unsignednbr(i / 10);
	ft_putchar_fd (i % 10 + '0', 1);
	return (count);
}

int	ft_printint(va_list args)
{
	int	i;
	int	count;

	i = va_arg(args, int);
	count = ft_putnbrprintf(i);
	return (count);
}

int	ft_printunsigned(va_list args)
{
	unsigned int	i;
	int				count;

	i = va_arg(args, unsigned int);
	count = ft_unsignednbr(i);
	return (count);
}
