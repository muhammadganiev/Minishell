/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_keymap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:13:56 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:18:02 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*merge_keymap(t_keymap *keymap)
{
	char *str;
	char *tmp;

	str = ft_strjoin(keymap->key, "=");
	if (keymap->val != NULL)
	{
		tmp = str;
		str = ft_strjoin(str, keymap->val);
		free(tmp);
	}
	return (str);
}

void	updt_keymap(t_keymap *keymap, char *value)
{
	size_t	len;
	size_t	index;

	len = ft_strchr_len(value, '=');
	index = len;
	keymap->key = ft_strldup(value, len);
	if (index >= ft_strlen(value))
	{
		if (ft_strchr(value, '='))
			keymap->val = ft_strdup("");
		else
			keymap->val = NULL;
		return ;
	}
	len = ft_strlen(&value[index]) + 1;
	keymap->val = ft_strldup(&value[index], len);
}

t_list	*find_key(t_list *lst, char *value)
{
	t_list	*cur;
	size_t	size;
	char	*key;

	cur = lst;
	size = ft_strchr_len(value, '=') + 1;
	key = ft_strldup(value, size);
	while (cur && !ft_strequal(key, ((t_keymap *)cur->content)->key))
		cur = cur->next;
	free(key);
	return (cur);
}

void	add_keymap(t_list **lst, char *keyval, int add)
{
	t_list		*cur;
	t_keymap	*keymap;

	cur = find_key(*lst, keyval);
	if (cur && !add)
	{
		keymap = (t_keymap *)cur->content;
		free(keymap->key);
		if (keymap->val && *keymap->val)
			free(keymap->val);
		updt_keymap(keymap, keyval);
	}
	else if (!cur)
	{
		keymap = malloc(sizeof(t_keymap));
		if (!keymap)
			ft_puterr("Malloc Error\n");
		updt_keymap(keymap, keyval);
		ft_lstadd_back(lst, ft_lstnew(keymap));
	}
}

void	rm_keymap(t_list **lst, char *key)
{
	t_list	*cur;
	t_list	*last;
	t_list	*next;

	cur = lst[0];
	last = NULL;
	while (cur)
	{
		next = cur->next;
		if (ft_strequal(((t_keymap *)cur->content)->key, key))
		{
			if (last)
				last->next = next;
			else
				lst[0] = next;
			clear_keymap(cur->content);
			free(cur);
		}
		last = cur;
		cur = next;
	}
}