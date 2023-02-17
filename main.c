/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:08 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:23:32 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/executor.h"
#include "includes/parsing.h"

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
static void	exit_fd(void)
{
	int	fd;

	fd = 0;
	while (fd <= 2)
	{
		close(fd);
		fd++;
	}
}

void	exit_app(int status)
{
	exit_fd();
	exit(status);
}

void	update_exitstatus(void)
{
	char	*temp;
	char	*keyvalue;

	temp = ft_itoa(g_shinfo.exit_status);
	keyvalue = ft_strjoin("?=", temp);
	free(temp);
	add_keymap(&g_shinfo.env->keymap, keyvalue, 0);
	free(keyvalue);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;

	(void)argc;
	(void)argv;
	g_shinfo.env = init_env(env);
	g_shinfo.exit_status = 0;
	def_input_sig();
	init_fd();
	while (get_cmd("minishell$ ", &line) != -1)
	{
		g_shinfo.pipe_out = -1;
		g_shinfo.cmd = sh_parse(line, g_shinfo.env);
		runcmd(g_shinfo.cmd);
		update_exitstatus();
		free(line);
		//clear_cmd(&g_shinfo.cmd);
		g_shinfo.cmd = NULL;
	}
	exit_app(g_shinfo.exit_status);
	return (g_shinfo.exit_status);
}