/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:13:58 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/17 19:06:27 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	close_fds(t_fdsmap *fds)
{
	int	i;

	i = 0;
	while (i < fds->size)
	{
		if (fds->map[i] >= 0)
			close(fds->map[i]);
		i++;
	}
}
