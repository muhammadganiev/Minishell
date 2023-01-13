/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 05:29:50 by gchernys          #+#    #+#             */
/*   Updated: 2022/04/16 19:48:32 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*stri;
	char	some;

	some = (char) c;
	stri = (char *)s;
	while (*stri != some && *stri)
		stri++;
	if (*stri == some)
		return (stri);
	return (0);
}
