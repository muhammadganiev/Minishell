/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: german <german@student.42.fr>              +#+  +:+       +#+        ssss*/
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:10:43 by muganiev          #+#    #+#             */
/*   Updated: 2023/01/29 15:05:53 by german           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strequal(char *s1, char *s2)
{
    return(s1 && s2 && ft_strlen(s1) == ft_strlen(s2) 
    && !ft_strncmp(s1, s2, ft_strlen(s1)));
}

int ft_strhas(char *s1, char *s2)
{
    return(s1 && s2 && !ft_strncmp(s1, s2, ft_strlen(s2)));
}

size_t  ft_strchr_len(char *s, char c)
{
    size_t  i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i);
}