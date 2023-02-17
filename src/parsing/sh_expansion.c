/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:09:53 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:49:49 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char *parse_key(char *quote)
{
	int		i;
	char	*key;

	i = 0;
	if (quote[i] && (ft_isdigit(quote[i]) || quote[i] == '?'))
		i++;
	else
	{
		while (quote[i] && ft_isalnum(quote[i]))
			i++;
		if (!i)
			return (NULL);
	}
	key = ft_strldup(quote, i + 1);
	if (!key)
		ft_puterr("malloc error\n");
	return (key);
}

t_keymap	*parse_keymap(char **quote, t_env *env)
{
	char	*key;
	t_list	*keyval;

	key = parse_key(*quote);
	if (!key)
		return (0);
	*quote += ft_strlen(key);
	keyval = find_key(env->keymap, key);
	free(key);
	if (!keyval)
		return (0);
	return ((t_keymap *)keyval->content);
}

int	expand_size(char **ps, int inside, t_env *env)
{
	t_keymap	*keymap;
	
	(*ps)++;
	if (**ps && !ft_strchr(SPACES, **ps))
	{
		keymap = parse_keymap(ps, env);
		if (keymap)
			return (ft_strlen(keymap->val));
		return (inside);
	}
	return (1);
}

int	expand_line(char **ps, char **argv, t_env *env)
{
	t_keymap	*keymap;

	(*ps)++;
	if (**ps && !ft_strchr(SPACES, **ps))
	{
		keymap = parse_keymap(ps, env);
		if (keymap)
		{
			**argv = '\0';
			*argv += ft_strlcat(*argv, keymap->val, ft_strlen(keymap->val) + 1);
			return (0);
		}
		return (1);
	}
	**argv = *((*ps) - 1);
	(*argv)++;
	return (0);
}

char	*expand(char *ps, t_env *env)
{
	char	*new;
	char	*new_tmp;
	char	*s;
	size_t	len;

	len = ft_strlen(ps);
	new = ft_calloc(sizeof(char), len + 1);
	if (!new)
		ft_puterr("malloc error\n");
	s = ps;
	new_tmp = new;
	while (*s)
	{
		if (*s == '$' && expand_line(&s, &new_tmp, env))
			continue ;
		*new_tmp = *s;
		new_tmp++;
		s++;
	}
	return (new);
}