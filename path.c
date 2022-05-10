#include "pipex.h"

char	*valid_path(char *cmd, char **paths_list)
{
	char	*tmp;
	char	*path;

	while (*paths_list != NULL)
	{
		tmp = ft_strjoin(*paths_list, "/");
		if (tmp == NULL)
			return (NULL);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (path == NULL)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		paths_list++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char *envp[])
{
	char	**paths_list;
	char	*path;

	while (ft_strncmp(*envp, "PATH", 4) != 0)
		envp++;
	while (*(*envp)++ != '=')
		;
	paths_list = ft_split(*envp, ':');
	path = valid_path(cmd, paths_list);
	free_split(paths_list);
	return (path);
}
