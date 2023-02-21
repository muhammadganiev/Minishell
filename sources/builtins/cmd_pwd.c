/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 16:05:06 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_pwd(void)
{
	char	*buff;

	buff = NULL;
	return (getcwd(buff, 0));
}

void	cmd_pwd(void)
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
		curr = find_keymap_key(g_appinfo.env->kms, "PWD");
		if (curr)
			ft_printf("%s\n", ((t_km *)curr->content)->val);
		else
			ft_printf("error: can't find PWD\n");
	}
}

void	ft_update_pwd(char *key, t_env *env)
{
	t_list	*curr;
	char	*keyvalue;
	char	*keytemp;
	char	*pwdtemp;

	keyvalue = NULL;
	curr = find_keymap_key(env->kms, key);
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
		free(((t_km *)curr->content)->key);
		free(((t_km *)curr->content)->val);
		update_keymap((t_km *)curr->content, keyvalue);
		free(keyvalue);
	}
}
