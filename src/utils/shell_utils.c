/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:45:37 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:35:02 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_cmd(char *prefix, char **buf)
{
	buf[0] = readline(prefix);
	if (buf[0] == 0)
		return (-1);
	add_history(buf[0]);
	return (0);
}
