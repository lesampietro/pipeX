/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:06 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/10 15:25:19 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/wait.h>

typedef struct s_pipex	t_pipex;

struct s_pipex
{
	int	fd_in;
	int	fd_out;
	int	pid[2];
	int	status;
};

// Pipes and child processes creation functions
void	execute(int argc, char **argv, char **envp);
void	child_process(char **argv, char **envp, t_pipex *data, int *fd);
void	brother_process(char **argv, char **envp, t_pipex *data, int *fd);
int		create_pipex(char **argv, char **envp, t_pipex *data);

// Paths to commands generation functions
char	*check_cmd(char **argv, char **envp);
char	*create_path(char *cmd, char **cmd_paths, char **envp);
void	check_permissions(char *cmd, char **cmd_paths);

// Memory cleansing and error functions
void	close_fds(void);
void	error(int status);
void	free_paths(char **paths);

#endif