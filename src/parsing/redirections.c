/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:36:40 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:45:14 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	heredoc(char *delim, t_env *env, int fd_pipe)
{
	char		*buf;
	char		*temp;

	while (1)
	{
		buf = readline("> ");
		if (!buf)
			break ;
		temp = expand(buf, env);
		if (ft_strequal(temp, delim))
		{
			free(buf);
			free(temp);
			break ;
		}
		// ft_fprintf(fd_pipe, "%s\n", temp); replace
		free(buf);
		free(temp);
	}
	close(fd_pipe);
	free(delim);
}

static void	child_heredoc(t_cmd *subcmd, char *delim, t_env *env, int pipe[2])
{
	signal(SIGINT, &sig_handler_heredoc);
	g_shinfo.cmd = subcmd;
	g_shinfo.pipe_in = pipe[1];
	g_shinfo.delim = delim;
	heredoc(delim, env, pipe[1]);
	close(pipe[0]);
}

t_cmd	*heredoccmd(t_cmd *subcmd, char *file, char *delim, t_env *env)
{
	int	p_id;
	int	stat;
	int	fd_pipe[2];

	if (pipe(fd_pipe) < 0)
		ft_puterr("pipe");
	if (g_shinfo.pipe_out >= 0)
		close(g_shinfo.pipe_out);
	g_shinfo.pipe_out = fd_pipe[0];
	p_id = ft_fork();
	if (p_id == 0)
	{
		free(file);
		child_heredoc(subcmd, delim, env, fd_pipe);
		exit_app(0);
	}
	free(delim);
	close(fd_pipe[1]);
	waitpid(p_id, &stat, 0);
	checkheredoc_status(stat, fd_pipe[0]);
	return (new_redircmd(subcmd, O_RDONLY, fd_pipe[0], file));
}

t_cmd	*parse_redircmd(t_cmd *cmd, char **cursor, t_env *env)
{
	int		token;
	char	*file;

	if (cmd == NULL || peek(cursor, "|") || !**cursor)
		return (cmd);
	if (peek(cursor, "<>"))
	{
		token = get_token(cursor);
		if (get_token(cursor) != 'a')
			ft_puterr("syntax error\n"); //modified
		write_argv(cursor, &file, env);
		if (token == '-')
			cmd = heredoccmd(cmd, ft_strdup("."), file, env);
		cmd = parse_redircmd(cmd, cursor, env);
		if (token == '<')
			cmd = new_redircmd(cmd, O_RDONLY, 0, file);
		else if (token == '>')
			cmd = new_redircmd(cmd, O_WRONLY | O_CREAT | O_TRUNC, 1, file);
		else if (token == '+')
			cmd = new_redircmd(cmd, O_WRONLY | O_CREAT | O_APPEND, 1, file);
	}
	else
		cmd = move_cursor(cmd, cursor, env);
	return (cmd);
}

t_cmd	*new_redircmd(t_cmd *subcmd, int mode, int fd, char *file)
{
	t_redircmd	*redircmd;

	redircmd = malloc(sizeof(t_redircmd));
	if (redircmd == NULL)
		exit(1);
	redircmd->type = REDIR;
	redircmd->subcmd = subcmd;
	redircmd->mode = mode;
	redircmd->fd = fd;
	redircmd->file = file;
	return ((t_cmd *)redircmd);
}