/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 16:05:28 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	verify_key(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (str[i] != '_' && !ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	cmd_export(char **argv, t_env *env)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(*argv[i]) || !verify_key(argv[i]))
		{
			ft_fprintf(2, "export: `%s': not a valid identifier\n", argv[i]);
			g_appinfo.exit_status = 1;
		}
		else
			add_keymap(&env->kms, argv[i], 0);
		i++;
	}
	if (i == 1)
		print_export(env->kms);
}
