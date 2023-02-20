/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 04:22:24 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/20 17:40:40 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next_lst;

	if (!lst)
		return (0);
	next_lst = lst;
	i = 0;
	while (next_lst)
	{
		i++;
		next_lst = next_lst->next;
	}
	return (i);
}
