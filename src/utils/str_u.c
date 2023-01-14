/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:10:43 by muganiev          #+#    #+#             */
/*   Updated: 2023/01/14 23:19:25 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strequals(char *s1, char *s2)
{
    return(s1 && s2 && ft_strlen(s1) == ft_strlen(s2) 
    && !ft_strncmp(s1, s2, ft_strlen(s1)));
}

int ft_strcontains(char *s1, char *s2)
{
    return(s1 && s2 && !ft_strncmp(s1, s2, ft_strlen(s2)));
}