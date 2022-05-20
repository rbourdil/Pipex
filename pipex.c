/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:15:53 by rbourdil          #+#    #+#             */
/*   Updated: 2022/05/20 17:17:46 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* open infile and outfile and add their fds to the fds map */

static void	open_files(t_fdsmap *fds, int argc, char *argv[])
{
	fds->map[0] = open(argv[1], O_RDONLY);
	if (fds->map[0] == -1)
		clean(argv[1], NULL, E_PERR);
	fds->map[fds->size - 1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fds->map[fds->size - 1] == -1)
		clean(argv[argc - 1], NULL, E_PERR);
}

/* 	does basically the same job as the "open_files" function except:
*	fds->map[0] is a temporary file filled with lines from standard input
*	the temporary file has to be closed and reopen to reset the fds' position
*	the function is called when "heredoc" is first arg to the program */

static void	open_files_heredoc(t_fdsmap *fds, int argc, char *argv[])
{
	char	*line;
	char	*limiter;

	limiter = ft_strjoin(argv[2], "\n");
	fds->map[0] = open(TMP_FILE, O_RDWR | O_CREAT | O_APPEND, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fds->map[0] == -1)
		clean("could not create temp file\n", NULL, E_MSG | E_EXIT);
	write(STDOUT_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL && ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
	{
		write(fds->map[0], line, ft_strlen(line));
		free(line);
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	free(limiter);
	close(fds->map[0]);
	fds->map[0]= open(TMP_FILE, O_RDONLY);
	if (fds->map[0] == -1)
		clean("cannot read from temporary file", NULL, E_MSG);
	fds->map[fds->size - 1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND,\
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fds->map[fds->size - 1] == -1)
		clean(argv[argc - 1], NULL, E_PERR);
}	

/* 	create the file descriptors map - its size is the number of fds necessary
*	--> two fds per pipe (one pipe for two commands) + files fds
*	opened fds are input in an alternating sequence of "read fds" and "write fds"
*	cmd1 reads on map[0] and write on map[1], cmd2 reads on map[2] and writes
*	on map[3] and so on and so forth... */

static void	map_fds(t_fdsmap *fds, int argc, char *argv[], int nb_pipes)
{
	int	pipefd[2];
	int	i;

	fds->size = 2 * (nb_pipes + 1);
	fds->map = (int *)malloc(sizeof(int) * fds->size);
	if (fds->map == NULL)
		clean("malloc", NULL, E_PERR | E_EXIT);
	ft_memset(fds->map, -1, fds->size);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		open_files_heredoc(fds, argc, argv);
	else
		open_files(fds, argc, argv);
	i = 0;
	while (i < nb_pipes)
	{
		if (pipe(pipefd) == -1)
			clean("pipe", fds, E_PERR | E_FDS | E_EXIT);
		fds->map[2 * i + 1] = pipefd[1];
		fds->map[2 * (i + 1)] = pipefd[0];
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_fdsmap	fds;
	int			nb_pipes;
	int			wstatus;
	pid_t		cpid;
	int			i;

	if ((argc < 6 && ft_strncmp(argv[1], "here_doc", 8) == 0) || argc < 5)
		clean("use: ./pipex (infile || here_doc LIMITER) cmd1 cmd2 \
... outfile\n", NULL, E_MSG | E_EXIT);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		nb_pipes = argc - 5;
	else
		nb_pipes = argc - 4;
	map_fds(&fds, argc, argv, nb_pipes);
	i = 0;
	while (i < nb_pipes + 1)
	{
		if ((cpid = fork()) == 0)
			exec_child(&fds, argv, envp, i);
		i++;
	}
	clean(NULL, &fds, E_FDS);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		unlink(TMP_FILE);
	waitpid(cpid, &wstatus, 0);
	while (wait(NULL) > 0)
		;
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	exit(EXIT_FAILURE);
}
