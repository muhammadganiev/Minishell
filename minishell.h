/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:05 by gchernys          #+#    #+#             */
/*   Updated: 2023/01/17 15:20:46 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h> // malloc, free, exit, getenv
// write, access, read, close, fork, getcwd, chdir
// unlink, execve, dup, dup2, pipe, isatty, ttyname, ttyslot
# include <unistd.h>
# include <fcntl.h> // open,
# include <signal.h> // signal, sigaction, sigemptyset, sigaddset, kill
# include <dirent.h> // opendir, readdir, closedir
# include <sys/wait.h> //wait, waitpid, wait3, wait4
# include <sys/stat.h> // stat, lstat, fstat
# include <sys/ioctl.h> // ioctl
# include <termios.h> //  tcsetattr, tcgetattr
# include <readline/readline.h> //readline, rl_on_new_line, rl_replace_line
# include <readline/history.h> //rl_clear_history, add_history, rl_redisplay
# include <term.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <errno.h>
# include "libft/libft.h"

enum e_token
{
	PIPE = '|',
	GREATER = '>',
	LESSER = 'Z',
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '"',
};

tybdef struct s_env
{
	t_list	*kms;
	char	**env;
} t_env;

void	sh_signal_handle(void);
void	sh_parse(void);
void	sh_lexer(char *line);

#endif