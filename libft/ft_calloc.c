/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 03:23:45 by gchernys          #+#    #+#             */
/*   Updated: 2021/11/04 09:30:32 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t counter, size_t size)
{
	void	*pnt;

	pnt = malloc(counter * size);
	if (pnt == NULL)
		return (pnt);
	ft_bzero(pnt, size * counter);
	return (pnt);
}
