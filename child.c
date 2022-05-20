#include "pipex.h"

void	exec_child(t_fdsmap *fds, char *argv[], char *envp[], int i)
{
	char	**opt;
	char	*cmd;
	int		offset;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		offset = 3;
	else
		offset = 2;
	if (fds->map[2 * i] == -1 || fds->map[2 * i + 1] == -1)
		clean(NULL, fds, E_FDS | E_EXIT);
	if ((dup2(fds->map[2 * i], STDIN_FILENO)) == -1)
		clean("dup2", fds, E_FDS | E_PERR | E_EXIT);
	if ((dup2(fds->map[2 * i + 1], STDOUT_FILENO)) == -1)
		clean("dup2", fds, E_FDS | E_PERR | E_EXIT);
	close_fds(fds);
	if ((opt = ft_split(argv[i + offset], ' ')) == NULL)
		clean("malloc", fds, E_PERR | E_FDS | E_EXIT);
	if ((cmd = get_path(opt[0], envp)) == NULL)
	{
		write(STDERR_FILENO, opt[0], ft_strlen(opt[0]));
		free_split(opt);
		clean(": command not found\n", fds, E_MSG | E_FDS | E_EXIT);
	}
	execve(cmd, opt, envp);
	clean("execve", fds, E_PERR | E_FDS | E_EXIT);
}
