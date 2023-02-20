/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:38:04 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:38:05 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long long num, int fd, int isupper)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, fd, isupper);
		ft_puthex(num % 16, fd, isupper);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (isupper)
				ft_putchar_fd((num - 10 + 'A'), fd);
			else
				ft_putchar_fd((num - 10 + 'a'), fd);
		}
	}
}
