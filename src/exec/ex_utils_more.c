/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_utils_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/19 22:43:01 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/executor.h"
#include "../../includes/parsing.h"

void	child_redircmd(t_redircmd *rcmd)
{
	int		fd_redirect;

	if (ft_strequal(rcmd->file, ".") && rcmd->fd > 2)
	{
		if (g_shinfo.pipe_out == -1)
			exit_app(g_shinfo.exit_status);
		dup2(rcmd->fd, STDIN_FILENO);
		close(rcmd->fd);
		runcmd(rcmd->subcmd);
		exit_app(g_shinfo.exit_status);
	}
	close(rcmd->fd);
	fd_redirect = open(rcmd->file, rcmd->mode, 0666);
	if (fd_redirect < 0)
	{
		if (errno == 13)
		{
			ft_puterr("Permision denied");
			exit_app(1);
		}
		ft_puterr("No such file or directory");
		exit_app(1);
	}
	runcmd(rcmd->subcmd);
	exit_app(g_shinfo.exit_status);
}

void	print_env(t_list *lst)
{
	t_list	*curr;
	t_keymap	*km;

	curr = lst;
	while (curr)
	{
		km = (t_keymap *)curr->content;
		if (km->val != NULL && !ft_strequal(km->key, "OLDPWD")
			&& !ft_strequal(km->key, "?"))
			ft_printf("%s=%s\n", km->key, km->val);
		curr = curr->next;
	}
}

void	print_export(t_list *lst)
{
	t_list	*sorted;
	t_list	*curr;
	t_keymap	*km;

	sorted = sort_keymap_alpha(lst);
	curr = sorted;
	while (curr)
	{
		km = (t_keymap *)curr->content;
		if (km->val != NULL)
		{
			if (!ft_strequal(km->key, "_") && !ft_strequal(km->key, "?"))
				printf("declare -x %s=\"%s\"\n", km->key, km->val);
		}
		else
			printf("declare -x %s\n", km->key);
		curr = curr->next;
	}
	free(sorted);
}
