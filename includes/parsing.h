/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:34:10 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 14:03:41 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

// parser
t_cmd	*parsecmd(char *s, t_env *env);
t_cmd	*parseline(char **ps, char *es, t_env *env);
int		peek(char **ps, char *es, char *toks);

// exec
t_cmd	*parseexec(char **ps, char *es, t_env *env);
t_cmd	*execcmd(t_env *env);

// exec_utils
int		peekredir(char **ps, char *es, char **temp, t_env *env);
t_cmd	*clearexec(t_cmd *cmd, char **ps, char *es);

// pipe
t_cmd	*parsepipe(char **ps, char *es, t_env *env);
t_cmd	*pipecmd(t_cmd *left, t_cmd *right);

// redirs
t_cmd	*parsingredirs(t_cmd *cmd, char **ps, char *es, t_env *env);
t_cmd	*redircmd(t_cmd *subcmd, char *file, int mode, int fd);

// redirs_utils
void	heredoc(char *delim, t_env *env, int fd_pipe);
t_cmd	*heredoccmd(t_cmd *subcmd, char *file, char *delim, t_env *env);

// block
t_cmd	*parseblock(char **ps, char *es, t_env *env);

// quote
int		parsequote(char **ps, char *es, char **argv, t_env *env);

// token
int		gettoken(char **ps, char *es, char **argv, t_env *env);

// expansion
int		expandsize(char **ps, char *es, int in_quote, t_env *env);
int		expandline(char **ps, char *es, char **argv, t_env *env);
char	*expansion(char *ps, char *es, t_env *env);

#endif