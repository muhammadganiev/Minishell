/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:08 by gchernys          #+#    #+#             */
/*   Updated: 2023/01/12 19:05:04 by gchernys         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	// sh_signal_handle();
	while (1)
	{
		sh_parse();
	}
}