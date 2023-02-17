/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:50:06 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 06:51:17 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_strgreater(char *s1, char *s2)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len && s2[i])
	{
		if (s2[i] > s1[i])
			return (1);
		if (s2[i] < s1[i])
			return (0);
		i++;
	}
	return (ft_strlen(s2) > len);
}

static void	swap_keymap(t_list **lst, t_keymap *km, t_list *prev, t_list *cur)
{
	if (!prev)
	{
		lst[0] = ft_lstnew(km);
		lst[0]->next = cur;
	}
	else
	{
		prev->next = ft_lstnew(km);
		prev->next->next = cur;
	}
}

static void	insert_keymap_alpha(t_list **lst, t_keymap *km)
{
	t_list	*cur;
	t_list	*prev;
	t_keymap	*km_cur;

	cur = lst[0];
	prev = NULL;
	while (cur)
	{
		km_cur = (t_keymap *)cur->content;
		if (!is_strgreater(km_cur->key, km->key))
		{
			swap_keymap(lst, km, prev, cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	ft_lstadd_back(lst, ft_lstnew(km));
}

t_list	*sort_keymap_alpha(t_list *lst)
{
	t_list	*new;
	t_list	*cur;
	t_keymap	*km_cur;

	if (!lst)
		return (0);
	new = ft_lstnew(lst->content);
	cur = lst->next;
	while (cur)
	{
		km_cur = (t_keymap *)cur->content;
		insert_keymap_alpha(&new, km_cur);
		cur = cur->next;
	}
	return (new);
}