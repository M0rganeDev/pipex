/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:51:51 by morgane           #+#    #+#             */
/*   Updated: 2025/01/15 16:09:10 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include "unistd.h"
#include "utils.h"

static inline void	pipes_down(t_pipex *pipex)
{
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
}

static void	free_pipex(t_pipex *pipex)
{
	clear_map(pipex->all_paths);
	pipes_down(pipex);
}

static int	find_executable(t_pipex *pipex, int flag)
{
	char	**map;
	char	*cmd;
	char	**tmp;
	char	*buffer;
	int		i;

	map = ft_split(pipex->paths[flag], ' ');
	cmd = map[0];
	i = -1;
	while (pipex->all_paths[++i])
	{
		if (path_has_executable(pipex->all_paths[i], cmd))
		{
			tmp = ft_split(cmd, ' ');
			cmd = ft_strjoin("/", tmp[0]);
			buffer = ft_strjoin(pipex->all_paths[i], cmd);
			pipex->paths[flag] = buffer;
			clear_map(tmp);
			free(cmd);
			return (clear_map(map), 1);
		}
	}
	ft_println("could not find executable %s, check your $PATH", cmd);
	return (clear_map(map), 0);
}

static int	create_fork(t_pipex *pipex)
{
	int	pid1;
	int	pid2;

	pid1 = fork();
	if (pid1 == 0)
		exec_program(pipex, 0);
	pid2 = fork();
	if (pid2 == 0)
		exec_program(pipex, 1);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);
	return (0);
}

static int	start(char **argv, char **env)
{
	t_pipex	pipex;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * 64);
	if (access(argv[1], R_OK) != 0)
		return (ft_println("file %s is not usable !", argv[1]));
	if (access(argv[4], F_OK) == -1 || access(argv[4], W_OK))
		return (ft_println("file %s is not usable !", argv[4]));
	pipex = parse_argv(argv, env);
	if (!find_executable(&pipex, 0) || !find_executable(&pipex, 1))
		return (free_pipex(&pipex), 0);
	create_fork(&pipex);
	free(buffer);
	return (free_pipex(&pipex), 0);
}

int	main(int argc, char **argv, char **env)
{
	char	*error;

	if (argc != 5)
	{
		if (argc < 5)
			error = "not enough arguments";
		else
			error = "too many arguments";
		ft_println("Error : %s (got %d, expected 4)", error, argc - 1);
		return (0);
	}
	start(argv, env);
	return (0);
}
