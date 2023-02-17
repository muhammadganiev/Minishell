/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:59:16 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:57:54 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	checkquotes(char **cursor, char *quote, int *inside)
{
	if (!*inside && ft_strchr(QUOTES, **cursor))
		*quote = **cursor;
	if (**cursor == *quote)
	{
		*inside = !(*inside);
		(*cursor)++;
		return (1);
	}
	if (!*inside && (ft_strchr(SPACES, **cursor) || ft_strchr(SYMBOLS, **cursor)))
		return (-1);
	return (0);
}

int	pure_word_size(char *cursor)
{
	int len;

	len = 0;
	while (*cursor && !ft_strchr(SPACES, *cursor) && !ft_strchr(SYMBOLS, *cursor))
	{
		len++;
		cursor++;
	}
	return (len);
}

int	word_size(char *cursor, char *quote, t_env *env)
{
	int	len;
	int inside;
	int status;

	len = 0;
	inside = 0;
	status = 0;
	while (*cursor)
	{
		status = checkquotes(&cursor, quote, &inside);
		if (status == 1)
			continue;
		if (status == -1)
			break;
		if ((inside && *quote != '\'' && *cursor == '$') || (!inside && *cursor == '$'))
		{
			len += expand_size(&cursor, inside, env);
			continue;
		}
		len++;
		cursor++;
	}
	if (inside)
		return (-1);
	return (len);
}


void	writeword(char **cursor, char **argv, char *q, t_env *env)
{
	char	*str;
	int		iq;
	int		status;

	iq = 0;
	status = 0;
	str = *argv;
	while (**cursor)
	{
		status = checkquotes(cursor, q, &iq);
		if (status == 1)
			continue ;
		if (status == -1)
			break ;
		if ((iq && *q != '\'' && **cursor == '$') || (!iq && **cursor == '$'))
		{
			if (!expand_line(cursor, &str, env) || !iq)
				continue ;
			(*cursor)--;
		}
		*str = **cursor;
		str++;
		(*cursor)++;
	}
	*str = '\0';
}

int	write_argv(char **cursor, char **argv, t_env *env)
{
	int	len;
	char quote;
	
	quote = '\0';
	len = word_size(*cursor, &quote, env);
	if (len < 0)
	{
		ft_puterr("Error: wrong syntax\n");
		return (1);
	}
	*argv = malloc(sizeof(char) * (len + 1));
	if (!*argv)
		ft_puterr("malloc error\n");
	writeword(cursor, argv, &quote, env);
	return (0);
}