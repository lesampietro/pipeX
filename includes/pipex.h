/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:06 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/05 18:42:10 by lsampiet         ###   ########.fr       */
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

typedef struct	s_pipex t_pipex;

struct s_pipex
{
	int	fd_in;
	int	fd_out;
	int	pid;
};

char	*check_cmd(char **argv, char **envp);
void	error(void);

#endif