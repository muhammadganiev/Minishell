/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:49:45 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/11 06:30:18 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (0);
	while (s1[k] == s2[k] && s1[k] & s2[k] && k < (n - 1))
		k++;
	return (((unsigned char *)s1)[k] - ((unsigned char *)s2)[k]);
}
