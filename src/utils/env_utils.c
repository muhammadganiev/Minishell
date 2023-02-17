/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:28:44 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:43:38 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_keymap(void *content)
{
	t_keymap	*keymap;

	keymap = (t_keymap *)content;
	free(keymap->key);
	if (keymap->val && *keymap->val)
		free(keymap->val);
	free(keymap);
}

void	clear_env(t_env *env)
{
	if (!env)
		return ;
	ft_clearsplit(env->env);
	ft_lstclear(&env->keymap, clear_keymap);
	free(env->keymap);
	free(env);
}


pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_puterr("fork: Resource temporarily unavailable");
	return (pid);
}

static void	clear_redircmd(t_redircmd *redircmd)
{
	clear_cmd(redircmd->subcmd);
	free(redircmd->file);
}

void	clear_cmd(t_cmd *cmd)
{
	t_execmd	*ecmd;
	t_redircmd	*redircmd;
	t_pipecmd	*pipecmd;

	if (cmd == 0)
		return ;
	if (cmd->type == EXEC)
	{
		ecmd = (t_execmd *)cmd;
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
		ft_puterr("clear_cmd");
	free(cmd);
}