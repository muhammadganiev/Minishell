/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 16:07:31 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parsing.h"

int	exec(char *cmd, char **argv, t_env *env)
{
	define_exec_signals();
	if (ft_strequals(cmd, "exit"))
	{
		cmd_exit(argv, env);
		return (0);
	}
	g_appinfo.exit_status = 0;
	if (ft_strequals(cmd, "cd"))
		cmd_cd(argv, env);
	else if (ft_strequals(cmd, "env"))
		print_env(env->kms);
	else if (ft_strequals(cmd, "pwd"))
		cmd_pwd();
	else if (ft_strequals(cmd, "echo"))
		cmd_echo(argv);
	else if (ft_strequals(cmd, "export"))
		cmd_export(argv, env);
	else if (ft_strequals(cmd, "unset"))
		cmd_unset(argv, env);
	else
		cmd_execve(cmd, argv, env);
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
		g_appinfo.exit_status = WEXITSTATUS(stat);
	return (0);
}

int	child_pipecmd(t_cmd *cmd, int fd, int pipe_in, int pipe_out)
{
	int	p_id;

	g_appinfo.exit_status = 0;
	p_id = ft_fork();
	if (p_id == 0)
	{
		close(pipe_out);
		dup2(pipe_in, fd);
		close(pipe_in);
		runcmd(cmd);
		exit_app(g_appinfo.exit_status);
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
		print_error("pipe");
	p_ids[0] = child_pipecmd(pcmd->left, STDOUT_FILENO, fd_pipe[1], fd_pipe[0]);
	p_ids[1] = child_pipecmd(pcmd->right, STDIN_FILENO, fd_pipe[0], fd_pipe[1]);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(p_ids[0], NULL, 0);
	waitpid(p_ids[1], &stat, 0);
	if (WEXITSTATUS(stat))
		g_appinfo.exit_status = WEXITSTATUS(stat);
	return (0);
}

int	runcmd(t_cmd *cmd)
{
	t_execcmd	*ecmd;

	if (cmd == 0)
		return (1);
	if (cmd->type == EXEC)
	{
		ecmd = (t_execcmd *)cmd;
		if (ecmd->argv[0] == 0)
			return (1);
		if (exec(ecmd->argv[0], ecmd->argv, ecmd->env))
		{
			ft_fprintf(2, "exec %s failed\n", ecmd->argv[0]);
			return (1);
		}
	}
	else if (cmd->type == REDIR)
		return (run_redircmd(cmd));
	else if (cmd->type == PIPE)
		return (run_pipecmd(cmd));
	else
		print_error("runcmd");
	return (0);
}
