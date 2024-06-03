/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/02 22:42:26 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_args(int argc)
{
	if (argc != 4)
	{
		perror("Error: Wrong number of arguments\n");
		exit(1);
	}
}

void	exec_cmd(char *cmd, char **argv, char **envp)
{
	if (execve(cmd, argv, envp) == -1)
	{
		perror("Error: Command execution failed\n");
		exit(1);
	}
}

void	check_cmd(char **argv, char **envp)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;
	char	*cmd;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
	{
		perror("Error: PATH not found\n");
		exit(1);
	}
	path = ft_strchr(envp[i], '=') + 1;
	paths = ft_split(path, ':');
	j = 0;
	while (paths[j])
	{
		paths[j] = ft_strjoin(paths[j], "/");
		cmd = ft_strjoin(paths[j], argv[2]);
		if (access (cmd, X_OK | F_OK) == 0)
		{	
			exec_cmd(cmd, &argv[2], envp);
			return ;
		}
		free(cmd);
		free(paths[j]);
		j++;
	}
	perror("Error: Invalid command\n");
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_pipex	data;

	check_args(argc);
	data.fd_in = open(argv[1], O_RDONLY); 
	if (data.fd_in < 0)
	{
		perror("Error: Invalid input file\n");
		exit(1);
	}
	data.fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.fd_out < 0)
	{
		perror("Error: Invalid output file\n");
		close(data.fd_in);
		exit(1);
	}
	pipe(fd);
	data.pid = fork();
	if (data.pid == 0)
	{
		dup2(data.fd_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(data.fd_in);
		close(data.fd_out);
		check_cmd(argv, envp);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(data.fd_out, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(data.fd_in);
		close(data.fd_out);
		wait(NULL);
	}
return (0);
}