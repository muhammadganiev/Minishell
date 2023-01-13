/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:57:29 by gchernys          #+#    #+#             */
/*   Updated: 2021/11/10 16:24:23 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	c;
	long int	x;
	long int	z;

	c = 0;
	x = 1;
	z = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			x *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		z = (str[c] - '0') + (z * 10);
		c++;
	}
	if (z * x < -2147483648)
		return (-1);
	else if (z * x > 2147483647)
		return (0);
	return (z * x);
}
