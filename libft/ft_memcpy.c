/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:07:54 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/06 03:15:33 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	idc;

	if (dest == src || !n)
		return (dest);
	idc = 0;
	while (idc < n)
	{
		*((char *)dest + idc) = *((char *)src + idc);
		idc++;
	}
	return (dest);
}
