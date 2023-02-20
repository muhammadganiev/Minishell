/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 05:29:50 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:51 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
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
