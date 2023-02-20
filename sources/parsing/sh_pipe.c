/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:23:28 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:07:51 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	*parsepipe(char **ps, char *es, t_env *env)
{
	t_cmd	*cmd;

	cmd = parseexec(ps, es, env);
	if (peek(ps, es, "|"))
	{
		gettoken(ps, es, 0, env);
		cmd = pipecmd(cmd, parsepipe(ps, es, env));
	}
	return (cmd);
}

t_cmd	*pipecmd(t_cmd *left, t_cmd *right)
{
	t_pipecmd	*cmd;

	cmd = ft_calloc(sizeof(*cmd), 1);
	if (!cmd)
		print_error("malloc error");
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}
