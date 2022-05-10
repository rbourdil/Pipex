#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	pid_t	cpid;

	if (argc != 5)
		exit(EXIT_FAILURE);
	if (pipe(pipex.pipefd) == -1)
	clean(&pipex, "pipe", E_MSG | E_EXIT);
	cpid = fork();
	if (cpid == -1)
		clean(&pipex, "fork", E_MSG | E_PIPE | E_EXIT);
	if (cpid == 0)
		write_pipe(&pipex, argc, argv, envp);
	cpid = fork();
	if (cpid == -1)
		clean(&pipex, "fork", E_MSG | E_PIPE | E_EXIT);
	if (cpid == 0)
		read_pipe(&pipex, argc, argv, envp);
	clean(&pipex, NULL, E_PIPE);
	wait(NULL);
	wait(NULL);
	return (0);
}
