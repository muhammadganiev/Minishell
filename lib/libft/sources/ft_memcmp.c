/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:29:39 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:51 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			num;
	unsigned char	temp1;
	unsigned char	temp2;

	if (n == 0)
		return (0);
	num = 0;
	temp1 = ((unsigned char *)s1)[num];
	temp2 = ((unsigned char *)s2)[num];
	while ((num < n) && (temp1 == temp2))
	{
		temp1 = ((unsigned char *)s1)[num];
		temp2 = ((unsigned char *)s2)[num];
		num++;
	}
	return (temp1 - temp2);
}
