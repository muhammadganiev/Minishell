/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:12:04 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:12:28 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getcmd(char *prefix, char **buf)
{
	buf[0] = readline(prefix);
	if (buf[0] == 0)
		return (-1);
	add_history(buf[0]);
	return (0);
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		print_error("fork: Resource temporarily unavailable");
	return (pid);
}

static void	clear_redircmd(t_redircmd *redircmd)
{
	clear_cmd(redircmd->cmd);
	free(redircmd->file);
}

void	clear_cmd(t_cmd *cmd)
{
	t_execcmd	*ecmd;
	t_redircmd	*redircmd;
	t_pipecmd	*pipecmd;

	if (cmd == 0)
		return ;
	if (cmd->type == EXEC)
	{
		ecmd = (t_execcmd *)cmd;
		ft_clearsplit(ecmd->argv);
	}
	else if (cmd->type == REDIR)
	{
		redircmd = (t_redircmd *)cmd;
		clear_redircmd(redircmd);
	}
	else if (cmd->type == PIPE)
	{
		pipecmd = (t_pipecmd *)cmd;
		clear_cmd(pipecmd->left);
		clear_cmd(pipecmd->right);
	}
	else
		print_error("clear_cmd");
	free(cmd);
}
