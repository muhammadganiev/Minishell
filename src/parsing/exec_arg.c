/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:45:50 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 08:02:54 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/parsing.h"

void	read_argv(char **cursor)
{
	while (**cursor && !ft_strchr(SPACES, **cursor)
		&&!ft_strchr(SYMBOLS, **cursor))
	{
		(*cursor)++;
	}
}

int	get_argc(char *cursor)
{
	int	token;
	int	argc;

	argc = 0;
	while (!peek(&cursor, "|"))
	{
		token = get_token(&cursor);
		if (token == 0)
			break ;
		if (ft_strchr("+-<>", token))
		{
			read_argv(&cursor);
			continue ;
		}
		if (token != 'a')
			ft_puterr("syntax error\n");
		read_argv(&cursor);
		argc++;
	}
	return (argc);
}

int	set_argv(char *cursor, char **argv, t_env *env)
{
	int	token;
	int	argc;

	argc = 0;
	while (!peek(&cursor, "|"))
	{
		token = get_token(&cursor);
		if (token == 0)
			break ;
		if (ft_strchr("+-<>", token))
		{
			read_argv(&cursor);
			continue ;
		}
		if (token != 'a')
			ft_puterr("syntax");
		if (write_argv(&cursor, &argv[argc], env))
			return (1);
		argc++;
	}
	argv[argc] = 0;
	return (0);
}