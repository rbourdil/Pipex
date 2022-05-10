#include "pipex.h"

void	read_pipe(t_pipex *pipex, int argc, char *argv[], char *envp[])
{
	close(pipex->pipefd[1]);
	pipex->fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (pipex->fd == -1)
		clean(pipex, "open", E_MSG | E_EXIT);
	if (dup2(pipex->fd, STDOUT_FILENO) == -1)
		clean(pipex, "dup2", E_MSG | E_FD | E_PIPE | E_EXIT);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
		clean(pipex, "dup2", E_MSG | E_FD | E_PIPE | E_EXIT);
	clean(pipex, NULL, E_FD | E_PIPE);
	pipex->opt = ft_split(argv[3], ' ');
	pipex->cmd = get_path(pipex->opt[0], envp);
	if (pipex->cmd == NULL || pipex->opt == NULL)
		clean(pipex, NULL, E_CMD | E_OPT | E_EXIT);
	execve(pipex->cmd, pipex->opt, envp);
	clean(pipex, "execve", E_MSG | E_CMD | E_OPT | E_EXIT);
}

void	write_pipe(t_pipex *pipex, int argc, char *argv[], char *envp[])
{
		(void)argc;
		close(pipex->pipefd[0]);
		pipex->fd = open(argv[1], O_RDONLY);
		if (pipex->fd == -1)
			clean(pipex, "open", E_MSG | E_EXIT);
		if (dup2(pipex->fd, STDIN_FILENO) == -1)
			clean(pipex, "dup2", E_MSG | E_FD | E_PIPE | E_EXIT);
		if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
			clean(pipex, "dup2", E_MSG | E_FD | E_PIPE | E_EXIT);
		clean(pipex, NULL, E_FD | E_PIPE);
		pipex->opt = ft_split(argv[2], ' ');
		pipex->cmd = get_path(pipex->opt[0], envp);
		if (pipex->cmd == NULL || pipex->opt == NULL)
			clean(pipex, "path", E_CMD | E_OPT | E_EXIT | E_MSG);
		execve(pipex->cmd, pipex->opt, envp);
		clean(pipex, "execve", E_MSG | E_CMD | E_OPT | E_EXIT);
}
