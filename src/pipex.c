/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/01 18:59:52 by lsampiet         ###   ########.fr       */
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

char	*check_cmd(char **argv, char **envp)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;
	char	*cmd;

	i = 0;
	j = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_strchr(envp[i], '=');
	paths = ft_split(path, ':');
	cmd = ft_strjoin(paths[j], *argv);
	while (1)
	{
		cmd = ft_strjoin(paths[j], *argv);
		if (access (cmd, X_OK) == 0)
		{	
			execve(cmd, argv, envp);
			break;
		}
		j++;
	}
	return(cmd);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	
	check_args(argc);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error: Invalid input file\n");
		exit(1);
	}
	check_cmd(&argv[2], envp);
	// while(*envp)
	// {
	// 	ft_printf("%s\n", *envp);
	// 	envp++;
	// }

	
	// if (access("/usr/bin/ls", X_OK) == 0)

	close(fd1);
}