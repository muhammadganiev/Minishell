/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/19 22:55:24 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parsing.h"
#include "../../includes/executor.h"

void	check_cmddir(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return ;
		i++;
	}
	ft_puterr("command not found\n");
	exit_app(127);
}

static void	error(char *cmd)
{
	int			fstatus;
	struct stat	buff;

	if (errno == 8)
		exit_app(0);
	fstatus = stat(cmd, &buff);
	check_cmddir(cmd);
	if (!fstatus)
	{
		if (buff.st_mode & S_IFDIR)
			printf("%s: is a directory\n", cmd);
		else
		{
			printf("%s: ", cmd);
			perror(NULL);
		}
		exit_app(126);
	}
	printf("%s: ", cmd);
	perror(NULL);
	exit_app(127);
}

void	ft_execve(char *cmd, char **argv, t_env *env)
{
	char		*path;
	pid_t		p_id;
	int			status;

	updt_env(env);
	p_id = ft_fork();
	if (p_id == 0)
	{
		path = full_command_path(cmd, env->env);
		execve(path, argv, env->env);
		error(cmd);
	}
	waitpid(p_id, &status, 0);
	if (WEXITSTATUS(status))
		g_shinfo.exit_status = WEXITSTATUS(status);
}
