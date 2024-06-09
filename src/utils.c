/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/09 20:28:51 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_permissions(char *cmd)
{
	if (access(cmd, X_OK) == -1)
	{
		ft_putstr_fd("\033[31mError: Permission denied\n", 2);
		exit(126);
	}
}


char	*create_path(char **argv, char **envp)
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
		cmd = ft_strjoin(path, argv[0]);
		free(path);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	while (paths[i])
		free(paths[i--]);
	free(paths);
	return (NULL);
}

char *check_cmd(char **argv, char **envp)
{
	char *cmd;

	cmd = NULL;
	
	if (access(argv[0], F_OK) == 0)
	{
		cmd = ft_strdup(argv[0]);
		check_permissions(cmd);
		return (cmd);
	}
	else
	{
		cmd = create_path(argv, envp);
		if (access(cmd, F_OK) == 0)
			check_permissions(cmd);
	}
	return (cmd);
}

void	error(int status)
{
	perror("\033[31mError");
	exit(status);
}
