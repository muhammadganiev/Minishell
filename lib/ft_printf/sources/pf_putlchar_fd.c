/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:38:11 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:38:13 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putlchar_fd(char c, int fd, struct s_data data)
{
	int	len;

	len = 1;
	if (!data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	ft_putchar_fd(c, fd);
	if (data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	return (len);
}
