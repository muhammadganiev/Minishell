/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:37:07 by muganiev          #+#    #+#             */
/*   Updated: 2023/02/20 16:39:33 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parsing.h"

int	len_ch(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] == ch)
		return (i);
	return (-1);
}

// if string same retunt n

int	ncompare(char *str1, char *str2, int n)
{
	while (*str1 && *str2 && *str1 == *str2 && --n > 0)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}

// Connect comands

char	*make_command(char *path, char *bin)
{
	int		i;
	int		j;
	char	*buff;

	buff = malloc(sizeof(char) * (len_ch(path, 0) + len_ch(bin, 0) + 2));
	if (!buff)
		print_error("malloc error");
	i = 0;
	j = 0;
	while (path[j])
		buff[i++] = path[j++];
	buff[i++] = '/';
	j = 0;
	while (bin[j])
		buff[i++] = bin[j++];
	buff[i] = 0;
	return (buff);
}

// Dub until n

char	*str_ndup(char *str, unsigned int n)
{
	unsigned int	i;
	char			*buff;

	i = 0;
	buff = malloc(sizeof(char) * (n + 1));
	if (!buff)
		print_error("malloc error");
	while (i < n)
		buff[i++] = *str++;
	buff[n] = 0;
	return (buff);
}

char	*full_command_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*dir;
	char	*full;

	i = 0;
	while (env[i] && ncompare(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && len_ch(path, ':') > -1)
	{
		dir = str_ndup(path, len_ch(path, ':'));
		full = make_command(dir, cmd);
		free(dir);
		if (access(full, F_OK) == 0)
			return (full);
		free(full);
		path += len_ch(path, ':') + 1;
	}
	return (cmd);
}
