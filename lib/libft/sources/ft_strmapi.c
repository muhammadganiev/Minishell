/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:19:40 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:51 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	len(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*temp;

	if (!s || !f)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (len((char *)s) + 1));
	if (temp == NULL)
		return (NULL);
	index = 0;
	while (index < (len((char *)s)))
	{
		temp[index] = f(index, s[index]);
		index++;
	}
	temp[index] = '\0';
	return (temp);
}
