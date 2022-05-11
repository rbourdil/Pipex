/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:14:07 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/11 17:37:28 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_pipe(t_pipex *pipex, char *argv[], char *envp[])
{
	close(pipex->pipefd[1]);
	pipex->fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (pipex->fd == -1)
		clean(pipex, "outfile", E_PERR | E_EXIT);
	if (dup2(pipex->fd, STDOUT_FILENO) == -1)
		clean(pipex, "dup2", E_PERR | E_FD | E_PIPE | E_EXIT);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
		clean(pipex, "dup2", E_PERR | E_FD | E_PIPE | E_EXIT);
	clean(pipex, NULL, E_FD | E_PIPE);
	pipex->opt = ft_split(argv[3], ' ');
	if (pipex->opt == NULL)
		clean(pipex, "malloc", E_PERR | E_EXIT);
	pipex->cmd = get_path(pipex->opt[0], envp);
	if (pipex->cmd == NULL)
		clean(pipex, "command not found\n", E_MSG | E_CMD | E_OPT | E_EXIT);
	execve(pipex->cmd, pipex->opt, envp);
	clean(pipex, "execve", E_PERR | E_CMD | E_OPT | E_EXIT);
}

void	write_pipe(t_pipex *pipex, char *argv[], char *envp[])
{
	close(pipex->pipefd[0]);
	pipex->fd = open(argv[1], O_RDONLY);
	if (pipex->fd == -1)
		clean(pipex, "infile", E_PERR | E_EXIT);
	if (dup2(pipex->fd, STDIN_FILENO) == -1)
		clean(pipex, "dup2", E_PERR | E_FD | E_PIPE | E_EXIT);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		clean(pipex, "dup2", E_PERR | E_FD | E_PIPE | E_EXIT);
	clean(pipex, NULL, E_FD | E_PIPE);
	pipex->opt = ft_split(argv[2], ' ');
	if (pipex->opt == NULL)
		clean(pipex, "malloc", E_PERR | E_EXIT);
	pipex->cmd = get_path(pipex->opt[0], envp);
	if (pipex->cmd == NULL)
		clean(pipex, "command not found\n", E_CMD | E_OPT | E_EXIT | E_MSG);
	execve(pipex->cmd, pipex->opt, envp);
	clean(pipex, "execve", E_PERR | E_CMD | E_OPT | E_EXIT);
}
