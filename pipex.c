#include "pipex.h"

int	main(int argc, char *argv[], char *envp[]) {
	int		pipefd[2];
	int		wstatus;
	pid_t	cpid1;
	pid_t	cpid2;

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
	wstatus = 1;
	cpid1 = fork();
	if (cpid1 == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid1 == 0)
		write_pipe(pipefd, argv, envp);
	else
		close(pipefd[1]);
	cpid2 = fork();
	if (cpid2 == -1)
	{
		close(pipefd[0]);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid2 == 0)
		read_pipe(pipefd, argv, envp);
	else
		close(pipefd[0]);
	waitpid(cpid1, &wstatus, 0);
	waitpid(cpid2, &wstatus, 0);
	return (0);
}
