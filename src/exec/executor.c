/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/19 22:06:44 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/executor.h"
#include "../../includes/parsing.h"

int	exec(char *cmd, char **argv, t_env *env)
{
	define_exec_signals();
	if (ft_strequal(cmd, "exit"))
	{
		ft_exit(argv, env);
		return (0);
	}
	g_shinfo.exit_status = 0;
	if (ft_strequal(cmd, "cd"))
		ft_cd(argv, env);
	else if (ft_strequal(cmd, "env"))
		print_env(env->keymap);
	else if (ft_strequal(cmd, "pwd"))
		ft_pwd();
	else if (ft_strequal(cmd, "echo"))
		ft_echo(argv);
	else if (ft_strequal(cmd, "export"))
		ft_export(argv, env);
	else if (ft_strequal(cmd, "unset"))
		ft_unset(argv, env);
	else
		ft_execve(cmd, argv, env);
	return (0);
}

int	run_redircmd(t_cmd *cmd)
{
	t_redircmd	*rcmd;
	int			p_id;
	int			stat;

	rcmd = (t_redircmd *)cmd;
	p_id = ft_fork();
	if (p_id == 0)
		child_redircmd(rcmd);
	if (rcmd->fd > 2)
		close(rcmd->fd);
	waitpid(p_id, &stat, 0);
	if (WEXITSTATUS(stat))
		g_shinfo.exit_status = WEXITSTATUS(stat);
	return (0);
}

int	child_pipecmd(t_cmd *cmd, int fd, int pipe_in, int pipe_out)
{
	int	p_id;

	g_shinfo.exit_status = 0;
	p_id = ft_fork();
	if (p_id == 0)
	{
		close(pipe_out);
		dup2(pipe_in, fd);
		close(pipe_in);
		runcmd(cmd);
		exit_app(g_shinfo.exit_status);
	}
	return (p_id);
}

int	run_pipecmd(t_cmd *cmd)
{
	t_pipecmd	*pcmd;
	int			fd_pipe[2];
	int			p_ids[2];
	int			stat;

	pcmd = (t_pipecmd *)cmd;
	if (pipe(fd_pipe) < 0)
		ft_puterr("pipe");
	p_ids[0] = child_pipecmd(pcmd->left, STDOUT_FILENO, fd_pipe[1], fd_pipe[0]);
	p_ids[1] = child_pipecmd(pcmd->right, STDIN_FILENO, fd_pipe[0], fd_pipe[1]);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(p_ids[0], NULL, 0);
	waitpid(p_ids[1], &stat, 0);
	if (WEXITSTATUS(stat))
		g_shinfo.exit_status = WEXITSTATUS(stat);
	return (0);
}

int	runcmd(t_cmd *cmd)
{
	t_execmd	*ecmd;

	if (cmd == 0)
		return (1);
	if (cmd->type == EXEC)
	{
		ecmd = (t_execmd *)cmd;
		if (ecmd->argv[0] == 0)
			return (1);
		if (exec(ecmd->argv[0], ecmd->argv, ecmd->env))
		{
			ft_puterr("Exec Failed\n");
			return (1);
		}
	}
	else if (cmd->type == REDIR)
		return (run_redircmd(cmd));
	else if (cmd->type == PIPE)
		return (run_pipecmd(cmd));
	else
		ft_puterr("runcmd");
	return (0);
}
