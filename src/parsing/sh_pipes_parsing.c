/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pipes_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:23:28 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:50:53 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_cmd	*parse_pipe(char **cursor, t_env *env)
{
	t_cmd	*cmd;

	cmd = parse_execmd(cursor, env);
	if (peek(cursor, "|"))
	{
		get_token(cursor);
		cmd = new_pipecmd(cmd, parse_pipe(cursor, env));
	}
	return (cmd);
}

t_cmd	*new_pipecmd(t_cmd *left, t_cmd *right)
{
	t_pipecmd	*pipecmd;

	pipecmd = malloc(sizeof(t_pipecmd));
	if (pipecmd == NULL)
		exit(1);
	pipecmd->type = PIPE;
	pipecmd->left = left;
	pipecmd->right = right;
	return ((t_cmd *)pipecmd);
}