#include "pipex.h"

void	free_split(char **split)
{
	char	**p_split;

	p_split = split;
	while (*p_split != NULL)
		free(*p_split++);
	free(split);
}

void	free_pipex(t_pipex *pipex, const char *err_msg)
{
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	write(STDERR_FILENO, "\n", 1);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	free_split(pipex->opt);
	free(pipex->path);
	exit(EXIT_FAILURE);
}
