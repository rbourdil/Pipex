#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

#include <string.h>
#include <errno.h>

typedef struct s_pipex {
	int		pipefd[2];
	int		fd;
	char	*path;
	char	**opt;
}	t_pipex;

void	init_pipex(t_pipex *pipex);

void	write_pipe(int pipefd[2], char *argv[], char *envp[], t_pipex *pipex);
void	read_pipe(int pipefd[2], char *argv[], char *envp[], t_pipex *pipex);

void	free_split(char **split);
void	free_pipex(t_pipex *pipex, const char *err_msg);

#endif
