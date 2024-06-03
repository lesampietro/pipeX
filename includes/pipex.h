/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:06 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/02 19:01:59 by lsampiet         ###   ########.fr       */
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
typedef struct	s_pid t_pid;

struct s_pipex
{
	int	fd_in;
	int	fd_out;
	int	pid;
};

struct s_pid
{
	int	pid;
};

#endif