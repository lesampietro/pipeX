/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/31 17:18:36 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Tentar executar os argumentos/linha de comando com execve

void	check_args(int argc)
{
	if (argc != 5)
	{
		perror("Error: Wrong number of arguments\n");
		exit(1);
	}
}

void	main(int argc, char **argv)
{
	int	fd1;
	
	check_args(argc);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error: Invalid input file\n");
		exit(1);
	}
	
	
}