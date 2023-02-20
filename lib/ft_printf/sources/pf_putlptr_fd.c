/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlptr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:38:29 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:38:31 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putlptr_fd(unsigned long long ptr, int fd, struct s_data data)
{
	int	len;

	len = 2;
	if (ptr == 0)
		len++;
	else
		len += ft_hexlen(ptr);
	if (!data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
		write(1, "0", 1);
	else
		ft_puthex(ptr, fd, 0);
	if (data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	return (len);
}
