/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/05 19:28:12 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// RESOLVER LEAKS NA SPLIT!!!!!!!!!!!
char	*check_cmd(char **argv, char **envp)
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
		cmd = ft_strjoin(path, argv[0]);
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

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
