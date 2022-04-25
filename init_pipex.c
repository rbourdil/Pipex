#include "pipex.h"

void	init_pipex(t_pipex *pipex)
{
	pipex->fd = -1;
	pipex->opt = NULL;
	pipex->path = NULL;
	if (pipe(pipex->pipefd) == -1)
		free_pipex(pipex, strerror(errno));
}
