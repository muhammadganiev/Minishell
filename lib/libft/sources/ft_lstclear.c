/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 05:34:45 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 17:40:42 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_lst;

	if (!lst[0])
		return ;
	while (lst[0])
	{
		next_lst = lst[0]->next;
		ft_lstdelone(lst[0], del);
		lst[0] = next_lst;
	}
	lst[0] = NULL;
}
