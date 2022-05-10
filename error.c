#include "pipex.h"

void	clean(t_pipex *pipex, const char *msg, int options)
{
	if ((E_MSG & options) != 0)
		perror(msg);
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
