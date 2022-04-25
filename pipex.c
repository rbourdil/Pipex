#include "pipex.h"

int	main(int argc, char *argv[], char *envp[]) {
	t_pipex	pipex;
	pid_t	cpid;

	if (argc != 5)
	{
		write(STDERR_FILENO, "Invalid number of arguments\n", 28);
		exit(EXIT_FAILURE);
	}
	init_pipex(&pipex);
	cpid = fork();
	if (cpid == -1)
		free_pipex(&pipex, "fork");
	if (cpid == 0)
		write_pipe(pipex.pipefd, argv, envp, &pipex);
	else
		close(pipex.pipefd[1]);
	cpid = fork();
	if (cpid == -1)
		free_pipex(&pipex, "fork");
	if (cpid == 0)
		read_pipe(pipex.pipefd, argv, envp, &pipex);
	else
		close(pipex.pipefd[0]);
	wait(NULL);
	wait(NULL);
	return (0);
}
