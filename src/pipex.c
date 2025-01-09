/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:47:05 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 13:16:02 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include "libft.h"

static char	*find_path_env(char **env)
{
	int	index;

	index = -1;
	while (env[++index])
	{
		if (ft_strstart(env[index], "PATH"))
			return (ft_substr(env[index], 5, ft_strlen(env[index])));
	}
	return (NULL);
}

t_pipex	parse_argv(char **argv, char **env)
{
	int		index;
	t_pipex	pipex;

	pipex.files[0] = argv[1];
	pipex.files[1] = argv[4];
	pipex.paths[0] = argv[2];
	pipex.paths[1] = argv[3];
	pipex.env_path = find_path_env(env);
	pipex.all_paths = ft_split(pipex.env_path, ':');
	ft_println("Input file : %s", pipex.files[0]);
	ft_println("Output file : %s", pipex.files[1]);
	ft_println("First command : %s", pipex.paths[0]);
	ft_println("Second command : %s", pipex.paths[1]);
	ft_println("\nAll paths set in $PATH :\n\n");
	index = -1;
	while (pipex.all_paths[++index])
		ft_println("%s", pipex.all_paths[index]);
	ft_println("");
	return (pipex);
}
