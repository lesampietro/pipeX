/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/09 20:17:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// RESOLVER LEAKS NA SPLIT!!!!!!!!!!!
// RELINK MAKEFILE!!!!!!!
// 

void	execute(int argc, char **argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(argv[argc], ' ');
	cmd_path = check_cmd(cmd, envp);
	if (cmd_path == NULL)
	{
		ft_putstr_fd("\033[31mError: Command not found\n", 2);
		exit(127);
	}
	if (execve(cmd_path, cmd, envp) == -1)
		error(1);
}

void	child_process(char **argv, char **envp, t_pipex	*data, int *fd)
{
	data->fd_in = open(argv[1], O_RDONLY, 0777);
	if (data->fd_in == -1)
		error(1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(data->fd_in, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(data->fd_in);
	execute(2, argv, envp);
}

void	brother_process(char **argv, char **envp, t_pipex *data, int *fd)
{
	data->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_out == -1)
		error(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(data->fd_out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(data->fd_out);
	execute(3, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int				fd[2];
	static t_pipex	data;
	int				status;

	status = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error(1);
		data.pid[0] = fork();
		if (data.pid[0] == -1)
			error(1);
		if (data.pid[0] == 0)
			child_process(argv, envp, &data, fd);
		data.pid[1] = fork();
		if (data.pid[1] == 0)
			brother_process(argv, envp, &data, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(data.pid[0], NULL, 0);
		waitpid(data.pid[1], &status, 0);
	}
	else
		error(1);
	status = (status >> 8) & 0xff;
	return (status);
}
