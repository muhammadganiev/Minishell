/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:45:50 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:05:58 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	peekredir(char **ps, char *es, char **temp, t_env *env)
{
	if (peek(ps, es, "<>"))
	{
		gettoken(ps, es, 0, env);
		gettoken(ps, es, temp, env);
		free(*temp);
		return (1);
	}
	return (0);
}

t_cmd	*clearexec(t_cmd *cmd, char **ps, char *es)
{
	clear_cmd(cmd);
	*ps = es;
	return (0);
}
