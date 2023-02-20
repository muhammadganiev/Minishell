/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:04:38 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:08:14 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	*parsecmd(char *s, t_env *env)
{
	char	*es;
	t_cmd	*cmd;

	es = s + ft_strlen(s);
	cmd = parseline(&s, es, env);
	if (s != es)
	{
		ft_fprintf(2, "leftovers: %s\n", s);
		print_error("syntax");
	}
	return (cmd);
}

t_cmd	*parseline(char **ps, char *es, t_env *env)
{
	t_cmd	*cmd;

	cmd = parsepipe(ps, es, env);
	return (cmd);
}

int	peek(char **ps, char *es, char *toks)
{
	char	*s;

	s = *ps;
	while (s < es && ft_strchr(WHITESPACE, *s))
		s++;
	*ps = s;
	return (*s && ft_strchr(toks, *s));
}
