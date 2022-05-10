#include "pipex.h"

void	free_split(char **split)
{
	char	**p;

	if (split == NULL)
		return ;
	p = split;
	while (*p != NULL)
		free(*p++);
	free(split);
}
