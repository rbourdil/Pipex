/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:17:08 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/11 17:38:40 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "libft.h"

# define E_EXIT 0x1
# define E_PIPE 0x2
# define E_FD 0x4
# define E_CMD 0x8
# define E_OPT 0x10
# define E_MSG 0x20
# define E_PERR 0x40

typedef struct s_pipex {
	int		pipefd[2];
	int		fd;
	char	*cmd;
	char	**opt;
}	t_pipex;

char	*get_path(char *cmd, char *envp[]);

void	read_pipe(t_pipex *pipex, char *arv[], char *envp[]);
void	write_pipe(t_pipex *pipex, char *argv[], char *envp[]);

void	free_split(char **split);

void	clean(t_pipex *pipex, const char *msg, int options);

#endif
