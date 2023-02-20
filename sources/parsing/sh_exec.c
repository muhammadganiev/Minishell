/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:45:01 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 17:22:52 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parseargv_size(char *ps, char *es, t_env *env)
{
	int		tok;
	int		argc;
	char	*temp;

	argc = 0;
	while (!peek(&ps, es, "|)"))
	{
		if (peekredir(&ps, es, &temp, env))
			continue ;
		temp = NULL;
		tok = gettoken(&ps, es, &temp, env);
		if (tok == -1)
			return (0);
		if (tok == -2)
			continue ;
		free(temp);
		if (tok == 0)
			break ;
		if (tok != 'a')
			print_error("syntax");
		argc++;
	}
	return (argc);
}

static void	parseargv(t_execcmd *cmd, char **ps, char *es, t_env *env)
{
	int		tok;
	int		argc;
	char	*temp;

	argc = 0;
	while (!peek(ps, es, "|)"))
	{
		if (peekredir(ps, es, &temp, env))
			continue ;
		tok = gettoken(ps, es, &cmd->argv[argc], env);
		if (tok == -2)
			continue ;
		if (tok == 0)
			break ;
		if (tok != 'a')
			print_error("syntax");
		argc++;
	}
	cmd->argv[argc] = 0;
}

t_cmd	*parseexec(char **ps, char *es, t_env *env)
{
	t_execcmd	*cmd;
	t_cmd		*ret;
	char		*q;
	int			size;

	if (peek(ps, es, "("))
		return (parseblock(ps, es, env));
	ret = execcmd(env);
	cmd = (t_execcmd *)ret;
	q = *ps;
	ret = parsingredirs(ret, &q, es, env);
	if (!ret)
		return (clearexec((t_cmd *)cmd, ps, es));
	size = parseargv_size(*ps, es, env);
	if (!size)
		return (clearexec(ret, ps, es));
	cmd->argv = (char **)ft_calloc(sizeof(char *), size + 1);
	if (!cmd->argv)
		print_error("malloc error\n");
	parseargv(cmd, ps, es, env);
	return (ret);
}

t_cmd	*execcmd(t_env *env)
{
	t_execcmd	*cmd;

	cmd = ft_calloc(sizeof(*cmd), 1);
	if (!cmd)
		print_error("malloc error");
	cmd->type = EXEC;
	cmd->env = env;
	return ((t_cmd *)cmd);
}
