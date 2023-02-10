/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:55:48 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/01 21:12:47 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	t_env	*make_new_env(int size)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	if (!new_env)
		ft_puterr("Malloc Error\n");
	new_env->keymap = NULL;
	new_env->env = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_env->env)
		ft_puterr("Malloc Error\n");
	return (new_env);
}
