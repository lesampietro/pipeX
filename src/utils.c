/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/10 14:26:39 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_permissions(char *cmd, char **cmd_paths)
{
	if (access(cmd, X_OK) == -1)
	{
		ft_putstr_fd("\033[31mError: Permission denied\033[37m\n", 2);
		free(cmd);
		free_paths(cmd_paths);
		exit(126);
	}
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
		free(paths[i++]);
	free(paths);
}

char	*create_path(char **cmd_paths, char **envp)
{
	char	*path;
	char	**paths;
	char	*cmd;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(path, cmd_paths[0]);
		free(path);
		if (access(cmd, F_OK) == 0)
		{
			free_paths(paths);
			check_permissions(cmd, cmd_paths);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

char	*check_cmd(char **cmd_paths, char **envp)
{
	char	*cmd;

	cmd = NULL;
	if (access(cmd_paths[0], F_OK) == 0)
	{
		check_permissions(cmd_paths[0], cmd_paths);
		return (cmd);
	}
	else
		cmd = create_path(cmd_paths, envp);
	return (cmd);
}

void	error(int status)
{
	perror("\033[31mError");
	ft_putstr_fd("\033[37m", 2);
	exit(status);
}
