/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:34:36 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/21 16:07:31 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

// executor
int					exec(char *cmd, char **argv, t_env *env);
int					runcmd(t_cmd *cmd);

// builtins
void				cmd_echo(char **argv);
void				cmd_env(t_env *env);
void				cmd_exit(char **argv, t_env *env);
void				cmd_export(char **argv, t_env *env);
void				cmd_pwd(void);
char				*ft_get_pwd(void);
void				ft_update_pwd(char *key, t_env *env);
void				cmd_unset(char **argv, t_env *env);
void				cmd_cd(char **argv, t_env *env);
int					ft_chdir(char *path);
void				cmd_execve(char *cmd, char **argv, t_env *env);

// executor_utils
int					len_ch(char *str, char ch);
int					ncompare(char *str1, char *str2, int n);
char				*make_command(char *path, char *bin);
char				*str_ndup(char *str, unsigned int n);
char				*full_command_path(char *cmd, char **env);
unsigned long long	ft_atoull(char *str, int *minus);

// executor_utils2
void				child_redircmd(t_redircmd *rcmd);

#endif