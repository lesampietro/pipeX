/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:06 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/09 22:58:09 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/gnl/includes/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/wait.h>

# define ERRO

typedef struct s_pipex	t_pipex;

struct s_pipex
{
	int	fd_in;
	int	fd_out;
	int	pid[2];
};

char	*check_cmd(char **argv, char **envp);
char	*create_path(char **argv, char **envp);
void	check_permissions(char *cmd);
void	error(int status);
void	free_paths(char **paths);

#endif