/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/05 13:21:02 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_args(int argc)
{
	if (argc != 3)
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

char	*check_cmd(char *argv, char **envp)
{
	int		i;
	char	*path;
	char	**paths;
	char	*cmd;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(path, argv);
		free(path);
		if (access (cmd, X_OK | F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	while (paths[i])
		free(paths[i--]);
	free(paths);
	return (0);
}

// perror("Error: Invalid command\n");
// exit(1);

int	main(int argc, char **argv, char **envp)
{
	// int		fd[2];
	// t_pipex	data;

	check_args(argc);
	check_cmd(argv[2], envp);
	// data.fd_in = open(argv[1], O_RDONLY); 
	// if (data.fd_in < 0)
	// {
	// 	perror("Error: Invalid input file\n");
	// 	exit(1);
	// }
	// data.fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// if (data.fd_out < 0)
	// {
	// 	perror("Error: Invalid output file\n");
	// 	close(data.fd_in);
	// 	exit(1);
	// }
	// pipe(fd);
	// data.pid = fork();
	// if (data.pid == 0)
	// {
	// 	dup2(data.fd_in, STDIN_FILENO);
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	close(data.fd_in);
	// 	close(data.fd_out);
	// }
// 	else
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		dup2(data.fd_out, STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		close(data.fd_in);
// 		close(data.fd_out);
// 		wait(NULL);
// 	}
	return (0);
}

// Function execute
// exec_cmd(cmd, &argv[2], envp);


// Check for envp
// if (!envp[i])
// {
// 	perror("Error: PATH not found\n");
// 	exit(1);
// }