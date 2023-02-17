/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:04:38 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 08:01:46 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_cmd	*sh_parse(char *cursor, t_env *env)
{
	t_cmd	*command;
	if (!*cursor)
		return (0);
	command = parse_pipe(&cursor, env);
	return (command);
}
	
int	peek(char **cursor, char *token)
{
	while (**cursor && ft_strchr(SPACES, **cursor))
		(*cursor)++;
	return(**cursor && ft_strchr(token, **cursor));
}

t_cmd	*move_cursor(t_cmd *command, char **cursor, t_env *env)
{
	int	token;

	token = get_token(cursor);
	if (token == 0)
		return (0);
	if (token == 'a')
		(*cursor) += pure_word_size(*cursor);
	return (parse_redircmd(command, cursor, env));
}