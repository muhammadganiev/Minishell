/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:31:19 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:11:49 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_first_word(char *str)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	while (str[i] && !ft_strchr(WHITESPACE, str[i]))
		i++;
	len = i;
	new = ft_calloc(sizeof(char), len + 1);
	if (!new)
		print_error("malloc error\n");
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_remove_char(char *str, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c)
		{
			j = i;
			while (j < len)
			{
				str[j] = str[j + 1];
				j++;
			}
			len--;
			i--;
		}
		i++;
	}
}

char	*ft_strljoin(char *s1, char *s2, int n)
{
	char	*new;
	char	*s;

	new = ft_calloc(sizeof(char), n);
	if (!new)
		print_error("malloc error");
	s = new;
	s += ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s, s2, ft_strlen(s2) + 1);
	return (new);
}

void	ft_clearsplit(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
