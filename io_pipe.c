#include "pipex.h"

static char	*test_paths(char *cmd, char **dirs, t_pipex *pipex)
{
	int		errnum;
	char	*tmp;
	char	*path;

	while (*dirs != NULL)
	{
		if ((tmp = ft_strjoin(*dirs, "/")) == NULL)
		{
			free_split(dirs);
			free_pipex(pipex, strerror(errno));
		}
		if ((path = ft_strjoin(tmp, cmd)) == NULL)
		{
			errnum = errno;
			free(tmp);
			free_split(dirs);
			free_pipex(pipex, strerror(errnum));
		}
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		dirs++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char *envp[], t_pipex *pipex)
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
	if ((dirs = ft_split(*envp, ':')) == NULL)
		free_pipex(pipex, strerror(errno));
	path = test_paths(cmd, dirs, pipex);
	free_split(dirs);
	return (path);
}

void	write_pipe(int pipefd[2], char *argv[], char *envp[], t_pipex *pipex)
{
	int		fd;
	
	close(pipex->pipefd[0]);
	if ((pipex->opt = ft_split(argv[2], ' ')) == NULL)
		free_pipex(pipex, strerror(errno));
	if ((pipex->path = get_path(pipex->opt[0], envp, pipex)) == NULL)
		free_pipex(pipex, "Invalid_path");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		free_pipex(pipex, strerror(errno));
	if (dup2(fd, STDIN_FILENO) == -1)
		free_pipex(pipex, strerror(errno));
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		free_pipex(pipex, strerror(errno));
	close(pipex->pipefd[1]);
	execve(pipex->path, pipex->opt, envp);
	free_pipex(pipex, strerror(errno));
}

void	read_pipe(int pipefd[2], char *argv[], char *envp[], t_pipex *pipex)
{
	int		fd;
	
	if ((pipex->opt = ft_split(argv[3], ' ')) == NULL)
		free_pipex(pipex, strerror(errno));
	if ((pipex->path = get_path(pipex->opt[0], envp, pipex)) == NULL)
		free_pipex(pipex, "Invalid path");
	if ((fd = open(argv[4], O_WRONLY)) == -1)
		free_pipex(pipex, strerror(errno));
	if (dup2(fd, STDOUT_FILENO) == -1)
		free_pipex(pipex, strerror(errno));
	close(fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		free_pipex(pipex, strerror(errno));
	close(pipex->pipefd[0]);
	execve(pipex->path, pipex->opt, envp);
	free_pipex(pipex, strerror(errno));
}
