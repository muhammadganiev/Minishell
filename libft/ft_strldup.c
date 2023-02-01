/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:27:19 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/01 21:28:48 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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