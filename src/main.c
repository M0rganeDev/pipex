/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:51:51 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 13:15:25 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static void	clear_map(char **map);

static void	free_pipex(t_pipex *pipex)
{
	int	index;

	free(pipex->env_path);
	index = -1;
	clear_map(pipex->all_paths);
}

static void	clear_map(char **map)
{
	int	index;

	index = -1;
	while (map[++index])
		free(map[index]);
	free(map);
}

static int	find_executable(t_pipex *pipex, int flag)
{
	char	**map;
	char	*cmd;
	int		i;

	map = ft_split(pipex->paths[flag], ' ');
	cmd = map[0];
	i = -1;
	while (pipex->all_paths[++i])
	{
		if (path_has_executable(pipex->all_paths[i], cmd))
		{
			ft_println("found %s in %s", cmd, pipex->all_paths[i]);
			return (clear_map(map), 1);
		}
	}
	ft_println("could not find executable %s, check your $PATH", cmd);
	return (clear_map(map), 0);
}

static int	start(char **argv, char **env)
{
	t_pipex	pipex;

	if (access(argv[1], R_OK) != 0)
		return (ft_println("file %s is not usable !", argv[1]));
	if (access(argv[4], F_OK) == -1 || access(argv[4], W_OK))
		return (ft_println("file %s is not usable !", argv[4]));
	pipex = parse_argv(argv, env);
	if (!find_executable(&pipex, 0) || !find_executable(&pipex, 1))
		return (free_pipex(&pipex), 0);
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
