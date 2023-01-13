/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 04:03:48 by gchernys          #+#    #+#             */
/*   Updated: 2021/11/04 10:07:36 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*linker;

	linker = (t_list *)malloc(sizeof(t_list));
	if (linker == NULL)
		return (NULL);
	linker->content = (void *)content;
	linker->next = NULL;
	return (linker);
}
