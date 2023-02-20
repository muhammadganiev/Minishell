/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:09:53 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 16:06:09 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*parsekey(char *q, char *eq)
{
	int		i;
	char	*key;

	i = 0;
	if (&q[i] < eq && (ft_isdigit(q[i]) || q[i] == '?'))
		i++;
	else
	{
		while (&q[i] < eq && ft_isalnum(q[i]))
			i++;
		if (!i)
			return (NULL);
	}
	key = ft_strldup(q, i + 1);
	if (!key)
		print_error("malloc error\n");
	return (key);
}

t_km	*parsekeymap(char **q, char *eq, t_env *env)
{
	char	*key;
	t_list	*keyvalue;

	key = parsekey(*q, eq);
	if (!key)
		return (0);
	*q += ft_strlen(key);
	keyvalue = find_keymap_key(env->kms, key);
	free(key);
	if (!keyvalue)
		return (0);
	return ((t_km *)keyvalue->content);
}

int	expandsize(char **ps, char *es, int in_quote, t_env *env)
{
	t_km	*km;

	(*ps)++;
	if (*ps < es && !ft_strchr(WHITESPACE, **ps))
	{
		km = parsekeymap(ps, es, env);
		if (km)
			return (ft_strlen(km->val));
		return (in_quote);
	}
	return (1);
}

int	expandline(char **ps, char *es, char **argv, t_env *env)
{
	t_km	*km;

	(*ps)++;
	if (*ps < es && !ft_strchr(WHITESPACE, **ps))
	{
		km = parsekeymap(ps, es, env);
		if (km)
		{
			**argv = '\0';
			*argv += ft_strlcat(*argv, km->val, ft_strlen(km->val) + 1);
			return (0);
		}
		return (1);
	}
	**argv = *((*ps) - 1);
	(*argv)++;
	return (0);
}

char	*expansion(char *ps, char *es, t_env *env)
{
	char	*new;
	char	*new_temp;
	char	*s;
	size_t	len;

	len = ft_strclen(ps, *es) + 1;
	new = ft_calloc(sizeof(char), len);
	if (!new)
		print_error("malloc error\n");
	s = ps;
	new_temp = new;
	while (s < es)
	{
		if (*s == '$' && expandline(&s, es, &new_temp, env))
			continue ;
		*new_temp = *s;
		new_temp++;
		s++;
	}
	return (new);
}
