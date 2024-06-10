/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:48:18 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/10 17:37:39 by lsampiet         ###   ########.fr       */
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
		close_fds();
		exit(126);
	}
}

char	*create_path(char *cmd, char **cmd_paths, char **envp)
{
	char	*path;
	char	**paths;
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
		cmd = create_path(cmd, cmd_paths, envp);
	return (cmd);
}
