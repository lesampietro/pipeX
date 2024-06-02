/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/02 18:51:03 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Usar strcmp para achar a chave PATH usando a variavel envp (talvez com um loop)
// Depois pegar o valor de PATH (após o =) e com split, pegar os diferentes caminhos possíveis para os comandos de shell
// com strjoin colocamos o argv[2] ou o [3] no final de cada caminho e com access verificamos se o arquivo existe
// ao testar tdos os caminhos com access, podemos entrar no if para executar o comando execve já com o path correto


void	check_args(int argc)
{
	if (argc != 3)
	{
		perror("Error: Wrong number of arguments\n");
		exit(1);
	}
}

void	check_cmd(int argc, char **argv, char **envp, t_pipex data)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;
	char	*cmd;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_strchr(envp[i], '=') + 1;
	paths = ft_split(path, ':');
	j = 0;
	while (paths[j])
	{
		paths[j] = ft_strjoin(paths[j], "/");
		cmd = ft_strjoin(paths[j], argv[argc]);
		if (access (cmd, X_OK | F_OK) == 0)
		{	
			// execve(cmd, argv, data.fd_in);
			ft_printf("Command: %s\n", cmd);
			return ;
		}
		j++;
	}
	perror("Error: Invalid command\n");
	exit(1);
	(void)data;
}

int	main(int argc, char **argv, char **envp)
{
	// int		fd[2];
	t_pid	pid;
	t_pipex	data;

	check_args(argc);
	data.fd_in = open(argv[1], O_RDONLY);
	if (data.fd_in == -1)
	{
		perror("Error: Invalid input file\n");
		exit(1);
	}
	check_cmd(2, argv, envp, data);
	close(data.fd_in);
	(void)pid;
}