#include "pipex.h"

int	main(int argc, char *argv[], char *envp[]) {
	int		pipefd[2];
	pid_t	cpid;

	if (argc != 5)
	{
		write(STDOUT_FILENO, "Invalid number of arguments\n", 28);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cpid = fork();
	if (cpid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
		write_pipe(pipefd, argv, envp);
	else
		close(pipefd[1]);
	cpid = fork();
	if (cpid == -1)
	{
		close(pipefd[0]);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
		read_pipe(pipefd, argv, envp);
	else
		close(pipefd[0]);
	wait(NULL);
	wait(NULL);
	return (0);
}
