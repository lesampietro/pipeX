/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/10 14:08:47 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute(int argc, char **argv, char **envp)
{
	char	*cmd;
	char	**cmd_paths;

	cmd_paths = ft_split(argv[argc], ' ');
	cmd = check_cmd(cmd_paths, envp);
	if (cmd == NULL)
	{
		ft_putstr_fd("\033[31mError: Command not found\033[37m\n", 2);
		free(cmd);
		free_paths(cmd_paths);
		exit(127);
	}
	if (execve(cmd, cmd_paths, envp) == -1)
		error(1);
}

void	child_process(char **argv, char **envp, t_pipex	*data, int *fd)
{
	data->fd_in = open(argv[1], O_RDONLY, 0777);
	if (data->fd_in == -1)
	{
		close(fd[0]);
		close(fd[1]);
		error(1);
	}
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

int	create_pipex(char **argv, char **envp, t_pipex *data)
{
	int	fd[2];
	int	status;

	status = 0;
	if (pipe(fd) == -1)
		error(1);
	data->pid[0] = fork();
	if (data->pid[0] == -1)
		error(1);
	if (data->pid[0] == 0)
		child_process(argv, envp, data, fd);
	data->pid[1] = fork();
	if (data->pid[1] == 0)
		brother_process(argv, envp, data, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(data->pid[0], &status, 0);
	waitpid(data->pid[1], &status, 0);
	status = (status >> 8) & 0xff;
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	static t_pipex	data;
	int				status;

	if (argc == 5)
	{
		status = create_pipex(argv, envp, &data);
		return (status);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad usage.\n", 2);
		ft_putstr_fd("Expected: ./pipex infile cmd01 cmd02 outfile\033[37m\n", 2);
		exit(1);
	}
	return (0);
}
