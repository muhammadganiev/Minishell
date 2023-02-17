/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:47:46 by gchernys          #+#    #+#             */
/*   Updated: 2023/02/17 07:37:39 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	checkheredoc_status(int stat, int fd)
{
	if (WEXITSTATUS(stat))
	{
		g_shinfo.exit_status = WEXITSTATUS(stat);
		close(fd);
		g_shinfo.pipe_out = -1;
	}
}