/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 16:04:34 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_unset(char **argv, t_env *env)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		remove_keymap(&env->kms, argv[i]);
		i++;
	}
}
