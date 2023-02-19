/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/19 23:06:09 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parsing.h"
#include "../../includes/executor.h"

static int	ft_chspecial(char *path, char *key, t_list *kms)
{
	t_list	*km;

	km = find_key(kms, key);
	if (!path || (km && chdir(((t_keymap *)km->content)->val) < 0))
	{
		printf("cd: %s: No such file or directory\n", path);
		g_shinfo.exit_status = 1;
		return (2);
	}
	else if (!km)
	{
		printf("cd: %s not set\n", key);
		return (1);
	}
	return (0);
}

int	ft_chdir(char *path)
{
	char	*parse_path;

	parse_path = ft_first_word(path);
	if (chdir(parse_path) < 0)
	{
		printf("cd: %s: No such file or directory\n", parse_path);
		g_shinfo.exit_status = 1;
		free(parse_path);
		return (1);
	}
	free(parse_path);
	return (0);
}

void	ft_cd(char **argv, t_env *env)
{
	char	*path;
	char	*pwd;

	path = argv[1];
	if (!path || *path == '-')
	{
		if (!ft_chspecial(path, "OLDPWD", env->keymap))
		{
			pwd = ft_get_pwd();
			if (pwd)
			{
				printf("%s\n", pwd);
				free(pwd);
			}
		}
		return ;
	}
	if (!path || *path == '~')
	{
		ft_chspecial(path, "HOME", env->keymap);
		return ;
	}
	ft_update_pwd("OLDPWD", env);
	ft_chdir(path);
	ft_update_pwd("PWD", env);
}
