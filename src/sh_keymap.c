/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_keymap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:13:56 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/01 21:36:04 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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