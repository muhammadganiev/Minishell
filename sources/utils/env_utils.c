/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:28:44 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:10:53 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_keymap(void *content)
{
	t_km	*km;

	km = (t_km *)content;
	free(km->key);
	if (km->val && *km->val)
		free(km->val);
	free(km);
}

void	clear_env(t_env *env)
{
	if (!env)
		return ;
	ft_clearsplit(env->env);
	ft_lstclear(&env->kms, clear_keymap);
	free(env->kms);
	free(env);
}
