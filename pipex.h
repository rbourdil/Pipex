/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:17:08 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/20 17:08:01 by rbourdil         ###   ########.fr       */
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
# include "get_next_line.h"

# define TMP_FILE "jkfjbewkj293y823g23r823f802083h238h09e32hh"
# define E_PERR 0x01
# define E_FDS 0x02
# define E_MSG 0x04
# define E_EXIT 0x08

typedef struct s_fdsmap {
	int	*map;
	int	size;
}	t_fdsmap;

void	exec_child(t_fdsmap *fds, char *argv[], char *envp[], int i);

char	*get_path(char *cmd, char *envp[]);

void	free_split(char **split);
void	close_fds(t_fdsmap *fds);

void	clean(const char *err_msg, t_fdsmap *fds, int options);

#endif
