/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:15:53 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/11 17:49:45 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	pid_t	cpid1;
	pid_t	cpid2;
	int		wstatus;

	if (argc != 5)
		clean(&pipex, "use ./pipex infile cmd1 cmd2 outfile\n", E_MSG | E_EXIT);
	if (pipe(pipex.pipefd) == -1)
		clean(&pipex, "pipe", E_PERR | E_EXIT);
	cpid1 = fork();
	if (cpid1 == -1)
		clean(&pipex, "fork", E_PERR | E_PIPE | E_EXIT);
	if (cpid1 == 0)
		write_pipe(&pipex, argv, envp);
	cpid2 = fork();
	if (cpid2 == -1)
		clean(&pipex, "fork", E_PERR | E_PIPE | E_EXIT);
	if (cpid2 == 0)
		read_pipe(&pipex, argv, envp);
	clean(&pipex, NULL, E_PIPE);
	waitpid(cpid1, &wstatus, 0);
	waitpid(cpid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (0);
}
