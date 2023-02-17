/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:55:48 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:15:20 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

static void	updt_shlvl(t_env *new)
{
	t_list		*cur;
	t_keymap	*keymaps;
	char		*temp;
	char		*temp2;
	int			val;

	cur = find_key(new->keymap, "SHLVL");
	if (cur)
	{
		keymaps = (t_keymap *)cur->content;
		val = ft_atoi(keymaps->val);
		if (val >= 0)
		{
			temp = ft_itoa(val + 1);
			temp2 = ft_strjoin("SHLVL=", temp);
			free(temp);
			add_keymap(&new->keymap, temp2, 0);
			free(temp2);
			return ;
		}
		add_keymap(&new->keymap, "SHLVL=1", 0);
	}
}

t_env	*init_env(char **env)
{
	size_t		i;
	size_t		size;
	t_env		*new_env;
	t_keymap	*keymap;

	size = ft_strdlen(env);
	new_env = make_new_env(size);
	i = 0;
	while (i < size)
	{
		keymap = malloc(sizeof(t_keymap));
		if (!keymap)
			ft_puterr("Malloc Error\n");
		updt_keymap(keymap, env[i]);
		new_env->env[i] = ft_strdup(env[i]);
		ft_lstadd_back(&new_env->keymap, ft_lstnew(keymap));
		i++;
	}
	new_env->env[i] = ft_strdup("?=0");
	add_keymap(&new_env->keymap, new_env->env[i], 0);
	new_env->env[++i] = 0;
	add_keymap(&new_env->keymap, "OLDPWD", 1);
	updt_shlvl(new_env);
	return (new_env);
}

char	**get_env(t_list *list)
{
	t_list	*cur;
	char	**env;
	int		i;
	
	env = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!env)
		ft_puterr("Malloc Error\n");
	cur = list;
	i = 0;
	while (cur)
	{
		env[i++] = merge_keymap((t_keymap *)cur->content);
		cur = cur->next;
	}
	env[i] = 0;
	return (env);
}

void	updt_env(t_env *env)
{
	ft_clearsplit(env->env);
	env->env = get_env(env->keymap);
}