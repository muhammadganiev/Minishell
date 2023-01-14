/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:08 by gchernys          #+#    #+#             */
/*   Updated: 2023/01/14 20:49:03 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	sh_signal_handle(void)
// {
// 	if (signal(SIGINT, SIG_IGN))
// 		printf("\n");
// 	if (signal(SIGQUIT, SIG_IGN))
// 		;
// }

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	char	**line;

	line = argv;
	// while (get_cmd("minishell>$", line) >= 0)
	if (argc > 1)
	{
		sh_lexer(line);
		
	}
	return (0);
}