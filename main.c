/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:08 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/01 21:44:58 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_fd(void)
{
	int fd;

	fd = open("console", O_RDWR);
	while (fd >= 0)
	{
		if (fd >= 2)
			break ;
		fd = open("console", O_RDWR);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	char	*line;

	// g_shinfo.env = init_env();
	g_shinfo.exit_status = 0;
	def_input_sig();
	init_fd();
	while (get_cmd("minishell$ ", &line) != -1)
	{
		g_shinfo.pipe_out = -1;
		// g_shinfo.cmd = sh_parse(line, g_shinfo.env);
	}
}