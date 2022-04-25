#include "pipex.h"

void	free_split(char **split)
{
	char	**p_split;

	p_split = split;
	while (*p_split != NULL)
		free(*p_split++);
	free(split);
}
