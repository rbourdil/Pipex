#include "pipex.h"

static char	*test_paths(char *cmd, char **dirs)
{
	char	*tmp;
	char	*path;

	while (*dirs != NULL)
	{
		tmp = ft_strjoin(*dirs, "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		dirs++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char *envp[])
{
	char	**dirs;
	char	*path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			while (*(*envp)++ != '=')
				;
			break ;
		}
		envp++;
	}
	dirs = ft_split(*envp, ':');
	//add error handling
	path = test_paths(cmd, dirs);
	free_split(dirs);
	return (path);
}

void	write_pipe(int pipefd[2], char *argv[], char *envp[])
{
	int		fd;
	char	*path;
	char	**opt;
	
	close(pipefd[0]);
	if ((opt = ft_split(argv[2], ' ')) == NULL)
	{
		close(pipefd[1]);
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	if ((path = get_path(opt[0], envp)) == NULL)
	{
		close(pipefd[1]);
		free_split(opt);
		write(STDERR_FILENO, "Invalid command\n", 16);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		close(pipefd[1]);
		free_split(opt);
		free(path);
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(pipefd[1]);
		free_split(opt);
		free(path);
		close(fd);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		close(pipefd[1]);
		free_split(opt);
		free(path);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	execve(path, opt, envp);
	free_split(opt);
	free(path);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	read_pipe(int pipefd[2], char *argv[], char *envp[])
{
	int		fd;
	char	*path;
	char	**opt;
	
	if ((opt = ft_split(argv[3], ' ')) == NULL)
	{
		close(pipefd[0]);
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	if ((path = get_path(opt[0], envp)) == NULL)
	{
		close(pipefd[0]);
		free_split(opt);
		write(STDERR_FILENO, "Invalid command\n", 16);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[4], O_WRONLY)) == -1)
	{
		free_split(opt);
		free(path);
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(pipefd[0]);
		free_split(opt);
		free(path);
		close(fd);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		close(pipefd[0]);
		free_split(opt);
		free(path);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	execve(path, opt, envp);
	free_split(opt);
	free(path);
	perror("execve");
	exit(EXIT_FAILURE);
}
