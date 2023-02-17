/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:50:00 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 05:57:44 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	redirtoken(char **cursor)
{
	int	token;

	token = **cursor;
	if (**cursor == '>')
	{
		(*cursor)++;
		if (**cursor == '>')
		{
			(*cursor)++;
			token = '+';
		}
	}
	else if (**cursor == '<')
	{
		(*cursor)++;
		if (**cursor == '<')
		{
			(*cursor)++;
			token = '-';
		}
	}
	return (token);
}

int	get_token(char **cursor)
{
	int	token;

	while (**cursor && ft_strchr(SPACES, **cursor))
		(*cursor)++;
	token = **cursor;
	if (**cursor == '|')
		(*cursor)++;
	else if (**cursor == '>' || **cursor == '<')
		token = redirtoken(cursor);
	else if (**cursor)
		token = 'a';
	while (**cursor && ft_strchr(SPACES, **cursor))
		(*cursor)++;
	return (token);
}