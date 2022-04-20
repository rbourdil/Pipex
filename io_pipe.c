#include "pipex.h"

static char	**get_paths(char *envp[])
{
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			while (*(*envp)++ != '=')
				;
			return (ft_split(*envp, ':'));
		}
		envp++;
	}
	return (NULL);
}

static char	*find_path(char *prog, char **paths)
{
	char	*tmp;
	char	*prog_path;

	while (*paths != NULL)
	{
		tmp = ft_strjoin(*paths, "/");
		prog_path = ft_strjoin(tmp, prog);
		free(tmp);
		if (access(prog_path, X_OK) == 0)
			return (prog_path);
		free(prog_path);
		paths++;
	}
	return (NULL);
}

void	write_pipe(int pipefd[2], char *argv[], char *envp[])
{
	char	**paths;
	char	**params;
	int		fd;

	paths = get_paths(envp);
	params = ft_split(argv[2], ' ');
	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY);	
	if (fd == -1)
	{
		close(pipefd[1]);
		perror("infile");
		exit(EXIT_FAILURE);	
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(pipefd[1]);
		close(fd);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		close(pipefd[1]);
		close(fd);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	close(pipefd[1]);
	execve(find_path(*params, paths), params, envp);  
	close(pipefd[1]);
	close(fd);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	read_pipe(int pipefd[2], char *argv[], char *envp[])
{
	char	**paths;
	char	**params;
	int		fd;

	paths = get_paths(envp);
	params = ft_split(argv[3], ' ');
	close(pipefd[1]);
	fd = open(argv[4], O_WRONLY);	
	if (fd == -1)
	{
		close(pipefd[0]);
		perror("outfile");
		exit(EXIT_FAILURE);	
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(pipefd[0]);
		close(fd);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		close(pipefd[0]);
		close(fd);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	close(pipefd[0]);
	execve(find_path(*params, paths), params, envp);  
	close(pipefd[0]);
	close(fd);
	perror("execve");
	exit(EXIT_FAILURE);
}
