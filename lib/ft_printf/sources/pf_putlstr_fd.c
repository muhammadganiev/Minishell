/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:38:34 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:38:36 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlstr_fd(char *s, int fd, int n)
{
	int	i;

	i = 0;
	while (s && s[i] && i < n)
		ft_putchar_fd(s[i++], fd);
	return (i);
}

int	pf_putlstr_fd(char *str, int fd, struct s_data data)
{
	int	len;

	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	if (data.is_precision && data.precision < len)
		len = data.precision;
	if (!data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	if (!str)
		ft_putlstr_fd("(null)", fd, len);
	else
		ft_putlstr_fd(str, fd, len);
	if (data.is_left_justify)
		len += pf_width(data.width - len, data.is_zero, fd);
	return (len);
}
