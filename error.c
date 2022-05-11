/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:13:15 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/11 17:46:34 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean(t_pipex *pipex, const char *msg, int options)
{
	if ((E_PERR & options) != 0)
		perror(msg);
	if ((E_MSG & options) != 0)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	if ((E_PIPE & options) != 0)
	{
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
	}
	if ((E_FD & options) != 0)
		close(pipex->fd);
	if ((E_CMD & options) != 0)
	{
		free(pipex->cmd);
		pipex->cmd = NULL;
	}
	if ((E_OPT & options) != 0)
	{
		free_split(pipex->opt);
		pipex->opt = NULL;
	}
	if ((E_EXIT & options) != 0)
		exit(EXIT_FAILURE);
}
