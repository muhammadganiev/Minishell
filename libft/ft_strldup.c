/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:27:19 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/19 22:51:21 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(char *src, int size)
{
	char	*dest;

	if (!size)
		return (0);
	dest = malloc(sizeof(char) * (size));
	if (!dest)
		return (0);
	ft_strlcpy(dest, src, size);
	if (!dest)
		return(0);
	return (dest);
}