/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:34:10 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/17 07:44:42 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

t_cmd	*sh_parse(char *cursor, t_env *env);
int		redirtoken(char **cursor);
int		get_token(char **cursor);
void	read_argv(char **cursor);
int	get_argc(char *cursor);
int	set_argv(char *cursor, char **argv, t_env *env);
void	checkheredoc_status(int stat, int fd);
void	heredoc(char *delim, t_env *env, int fd_pipe);
t_cmd	*heredoccmd(t_cmd *subcmd, char *file, char *delim, t_env *env);
t_cmd	*parse_redircmd(t_cmd *cmd, char **cursor, t_env *env);
t_cmd	*new_redircmd(t_cmd *subcmd, int mode, int fd, char *file);
t_cmd	*parse_execmd(char **cursor, t_env *env);
t_cmd	*new_execmd(int argc, t_env *env);
char *parse_key(char *quote);
t_keymap	*parse_keymap(char **quote, t_env *env);
int	expand_size(char **ps, int inside, t_env *env);
int	expand_line(char **ps, char **argv, t_env *env);
char	*expand(char *ps, t_env *env);
t_cmd	*move_cursor(t_cmd *command, char **cursor, t_env *env);
int	peek(char **cursor, char *token);
t_cmd	*parse_pipe(char **cursor, t_env *env);
t_cmd	*new_pipecmd(t_cmd *left, t_cmd *right);
int	write_argv(char **cursor, char **argv, t_env *env);
void	writeword(char **cursor, char **argv, char *q, t_env *env);
int	word_size(char *cursor, char *quote, t_env *env);
int	pure_word_size(char *cursor);
int	redirtoken(char **cursor);
int	get_token(char **cursor);

#endif
