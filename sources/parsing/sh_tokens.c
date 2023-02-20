/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:50:00 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:07:35 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	redirtoken(char **ps, int *ret)
{
	if (**ps == '<')
	{
		(*ps)++;
		if (**ps == '<')
		{
			*ret = '-';
			(*ps)++;
		}
		return (1);
	}
	if (**ps == '>')
	{
		(*ps)++;
		if (**ps == '>')
		{
			*ret = '+';
			(*ps)++;
		}
		return (1);
	}
	return (0);
}

int	gettoken(char **ps, char *es, char **argv, t_env *env)
{
	int		ret;

	while (*ps < es && ft_strchr(WHITESPACE, **ps))
		(*ps)++;
	ret = **ps;
	if (**ps == '|' || **ps == '(' || **ps == ')')
		(*ps)++;
	else if (!redirtoken(ps, &ret) && **ps)
		ret = parsequote(ps, es, argv, env);
	while (*ps < es && ft_strchr(WHITESPACE, **ps))
		(*ps)++;
	return (ret);
}
