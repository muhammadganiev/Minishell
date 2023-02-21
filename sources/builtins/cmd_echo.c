/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 16:07:10 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_n_compere(char *flag)
{
	int	i;

	i = 0;
	if (flag != NULL)
	{
		if (flag[i] != '-')
			return (1);
		i++;
		while (flag[i])
		{
			if (flag[i] != 'n')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	cmd_echo(char **argv)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (ft_n_compere(argv[i]) == 0)
	{
		n++;
		i++;
	}
	while (argv[i] && argv)
	{
		ft_printf("%s", argv[i]);
		i++;
		if (argv[i])
			ft_printf(" ");
	}
	if (n == 0)
		ft_printf("\n");
}
