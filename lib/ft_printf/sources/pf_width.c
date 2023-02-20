/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:38:47 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:38:48 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_width(int n, int is_zero, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (is_zero)
			write(fd, "0", 1);
		else
			write(fd, " ", 1);
		i++;
	}
	return (i);
}
