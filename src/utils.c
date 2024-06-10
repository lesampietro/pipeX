/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/10 15:13:29 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(void)
{
	close(2);
	close(1);
	close(0);
}

void	error(int status)
{
	perror("\033[31mError");
	ft_putstr_fd(" \033[37m", 2);
	exit(status);
}

void free_paths(char **paths)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
		free(paths[i++]);
	free(paths);
}
