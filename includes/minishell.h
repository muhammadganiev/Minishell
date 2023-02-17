/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:05 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:43:50 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <term.h>
# include <errno.h>
# include "../libft/libft.h"

# define SYMBOLS "|><"
# define SPACES " \t\r\n\f\v"
# define QUOTES "\'\""

typedef enum e_cmdtype
{
	EXEC = 0,
	REDIR = 1,
	PIPE = 2,
}	t_cmdtype;

typedef struct s_keymap
{
	char	*key;
	char	*val;
}	t_keymap;

typedef struct s_env
{
	t_list	*keymap;
	char	**env;
}	t_env;

typedef struct s_cmd
{
	int	type;
}	t_cmd;

typedef struct s_execmd
{
	int		type;
	char	**argv;
	t_env	*env;
}	t_execmd;

typedef struct s_pipecmd
{
	int		type;
	t_cmd	*left;
	t_cmd	*right;
}	t_pipecmd;

typedef struct s_redircmd
{
	int		type;
	t_cmd	*subcmd;
	int		mode;
	int		fd;
	char	*file;
}	t_redircmd;

typedef struct s_shinfo
{
	t_cmd		*cmd;
	t_env		*env;
	int			exit_status;
	int			pipe_out;
	int			pipe_in;
	char		*delim;
}	t_shinfo;

extern	t_shinfo g_shinfo;

int		ft_strequal(char *s1, char *s2);
int		ft_strhas(char *s1, char *s2);
size_t	ft_strchr_len(char *s, char c);
int		get_cmd(char *prefix, char **buf);
t_list	*find_key(t_list *lst, char *value);
void	updt_keymap(t_keymap *keymap, char *value);
char	*merge_keymap(t_keymap *keymap);
void	ft_clearsplit(char **str);
void	add_keymap(t_list **lst, char *keyval, int add);
void	rm_keymap(t_list **lst, char *key);
void	clear_env(t_env *env);
void	clear_keymap(void *content);
t_env	*init_env(char **env);
char	**get_env(t_list *list);
void	updt_env(t_env *env);
void	sig_handler_heredoc(int sig_num);
char	*ft_first_word(char *str);
void	ft_remove_char(char *str, char c);
char	*ft_strljoin(char *s1, char *s2, int n);
void	ft_clearsplit(char **str);
size_t	ft_strdlen(char **s);
void	exit_app(int status);
void	update_exitstatus(void);
void	ctrl_c(int sig);
void	ctrl_d(void);
void	define_exec_signals(void);
void	def_input_sig(void);
void	clear_cmd(t_cmd *cmd);
pid_t	ft_fork(void);
void	clear_cmd(t_cmd *cmd);

#endif