/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:13:15 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/20 17:07:06 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* prints an error message, closes all open files descriptors and exits */

void	clean(const char *err_msg, t_fdsmap *fds, int options)
{
	if ((options & E_PERR) != 0)
		perror(err_msg);
	if ((options & E_FDS) != 0)
	{
		close_fds(fds);
		free(fds->map);
		fds->map = NULL;
	}
	if ((options & E_MSG) != 0)
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	if ((options & E_EXIT) != 0)
		exit(EXIT_FAILURE);
}
