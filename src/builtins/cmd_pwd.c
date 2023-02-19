/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/19 23:07:28 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parsing.h"
#include "../../includes/executor.h"

char	*ft_get_pwd(void)
{
	char	*buff;

	buff = NULL;
	return (getcwd(buff, 0));
}

void	ft_pwd(void)
{
	char	*pwd;
	t_list	*curr;

	pwd = ft_get_pwd();
	if (pwd)
	{
		ft_printf("%s\n", pwd);
		free(pwd);
	}
	else
	{
		curr = find_key(g_shinfo.env->keymap, "PWD");
		if (curr)
			printf("%s\n", ((t_keymap *)curr->content)->val);
		else
			printf("error: can't find PWD\n");
	}
}

void	ft_update_pwd(char *key, t_env *env)
{
	t_list	*curr;
	char	*keyvalue;
	char	*keytemp;
	char	*pwdtemp;

	keyvalue = NULL;
	curr = find_key(env->keymap, key);
	if (curr)
	{
		keytemp = ft_strjoin(key, "=");
		pwdtemp = ft_get_pwd();
		if (!pwdtemp)
		{
			free(keytemp);
			free(pwdtemp);
			return ;
		}
		keyvalue = ft_strjoin(keytemp, pwdtemp);
		free(keytemp);
		free(pwdtemp);
		free(((t_keymap *)curr->content)->key);
		free(((t_keymap *)curr->content)->val);
		updt_keymap((t_keymap *)curr->content, keyvalue);
		free(keyvalue);
	}
}
