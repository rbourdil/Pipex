#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	write_pipe(int pipefd[2], char *argv[], char *envp[]);
void	read_pipe(int pipefd[2], char *argv[], char *envp[]);
void	free_split(char **split);

#endif
