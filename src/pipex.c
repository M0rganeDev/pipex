/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:47:05 by morgane           #+#    #+#             */
/*   Updated: 2025/01/16 13:58:45 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include "unistd.h"
#include "utils.h"
#include <errno.h>

static char	*find_path_env(char **env)
{
	int	index;

	index = -1;
	while (env[++index])
	{
		if (ft_strstart(env[index], "PATH"))
			return (env[index] + 5);
	}
	return (NULL);
}

/*
 *	"Comment is invalid in this scope"
 *	
 * static char	**parse_args(char *full_str)
{
	char	**args;

	args = ft_split(full_str, ' ');
	return (args);
}
	ft_println("Input file : %s", pipex.files[0]);
	ft_println("Output file : %s", pipex.files[1]);
	ft_println("First command : %s", pipex.paths[0]);
	ft_println("Second command : %s", pipex.paths[1]);
	ft_println("\nAll paths set in $PATH :\n\n");
static void	print_map(char **map)
{
	int	index;

	index = -1;
	while (map[++index])
		ft_println("%s", map[index]);
	ft_println("%s", map[index]);

	int		index;
	ft_println("argv : %s flag: %d, formated: %d",
	pipex->base_argv[flag + 2], flag, flag + 2);
	ft_println("%s", pipex->paths[flag]);
	index = -1;
	while (pipex.all_paths[++index])
		ft_println("%s", pipex.all_paths[index]);
	ft_println(" ");
}*/

int	exec_program(t_pipex *pipex, int flag)
{
	char	**parsed_args;

	dup2(pipex->channel[1 - flag], 1 - flag);
	close(pipex->channel[flag]);
	dup2(pipex->pipes[flag], flag);
	parsed_args = ft_split(pipex->base_argv[flag + 2], ' ');
	if (execve(pipex->paths[flag], parsed_args, pipex->base_env) != 0)
		return (errno);
	return (0);
}

t_pipex	parse_argv(char **argv, char **env)
{
	t_pipex	pipex;

	pipex.base_env = env;
	pipex.base_argv = argv;
	pipex.files[0] = argv[1];
	pipex.paths[0] = argv[2];
	pipex.paths[1] = argv[3];
	pipex.files[1] = argv[4];
	pipex.env_path = find_path_env(env);
	pipex.all_paths = ft_split(pipex.env_path, ':');
	return (pipex);
}
