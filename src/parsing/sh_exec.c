/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:45:01 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:45:43 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_cmd	*parse_execmd(char **cursor, t_env *env)
{
	t_execmd	*execmd;
	t_cmd		*cmd;
	int			argc;

	argc = get_argc(*cursor);
	if (argc == 0)
		return (0);
	cmd = new_execmd(argc, env);
	execmd = (t_execmd *)cmd;
	if (set_argv(*cursor, execmd->argv, env))
	{
		clear_cmd(cmd);
		return (0);
	}
	cmd = parse_redircmd(cmd, cursor, env);
	if (!cmd)
	{
		clear_cmd(cmd);
		return (0);
	}
	return (cmd);
}

t_cmd	*new_execmd(int argc, t_env *env)
{
	t_execmd	*execmd;

	execmd = malloc(sizeof(t_execmd));
	if (execmd == NULL)
		exit(1);
	execmd->type = EXEC;
	execmd->argv = (char **)malloc(sizeof(char *) * (argc + 1));
	if (execmd->argv == NULL)
		exit(1);
	execmd->env = env;
	return ((t_cmd *)execmd);
}