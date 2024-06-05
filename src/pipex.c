/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/05 16:07:44 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute(char **argv, char **envp)
{
	char *cmd;
	
	cmd = check_cmd(*argv, envp);
	if (execve(cmd, argv, envp) == -1)
		error();
}

void	child_process(char **argv, char **envp, t_pipex	*data, int *fd)
{
	data->fd_in = open(argv[1], O_RDONLY, 0777);
	if (data->fd_in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(data->fd_in, STDIN_FILENO);
	close(fd[0]);
	// close(fd[1]);
	// close(data->fd_in);
	// close(data->fd_out);
	execute(&argv[2], envp);
}

void	parent_process(char **argv, char **envp, t_pipex *data, int *fd)
{
	data->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_in == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(data->fd_out, STDOUT_FILENO);
	// close(fd[0]);
	close(fd[1]);
	// close(data->fd_in);
	// close(data->fd_out);
	execute(&argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_pipex	data;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		data.pid = fork();
		if (data.pid == -1)
			error();
		if (data.pid == 0)
			child_process(argv, envp, &data, fd);
		waitpid(data.pid, NULL, 0);
		parent_process(argv, envp, &data, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad usage\n", 2);
		ft_putstr_fd("Ex: ./pipex file01 cmd01 cmd02 file02\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

