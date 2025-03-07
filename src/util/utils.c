/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:48 by morgane           #+#    #+#             */
/*   Updated: 2025/01/22 10:54:35 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	path_has_executable(const char *path, const char *cmd)
{
	char	*joined_path;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	joined_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (access(joined_path, X_OK) == 0)
	{
		free(joined_path);
		return (1);
	}
	free(joined_path);
	return (0);
}

int	ft_strend(const char *target, const char *end)
{
	size_t	end_size;
	size_t	target_size;

	end_size = ft_strlen(end);
	target_size = ft_strlen(target);
	if (target_size < end_size)
		return (0);
	while (end_size != 0)
	{
		if (target[target_size] != end[end_size])
			return (0);
		--end_size;
		--target_size;
	}
	return (1);
}

int	ft_strstart(const char *target, const char *needle)
{
	size_t	needle_size;
	size_t	target_size;
	size_t	index;

	index = 0;
	needle_size = ft_strlen(needle);
	target_size = ft_strlen(target);
	if (target_size < needle_size)
		return (0);
	while (index != needle_size)
	{
		if (target[index] != needle[index])
			return (0);
		++index;
	}
	return (1);
}

// look for a relative / absolute path to find an executable in.
// also turns pipex->paths into malloc'd strings 
// so I dont have to check if they were malloc'd or not
int	search_relative(t_pipex *pipex, int flag)
{
	char	*tmp;

	ft_println("searching rel/abs cmd in %s", pipex->paths[flag]);
	if (access(pipex->paths[flag], X_OK) == 0)
	{
		tmp = ft_strdup(pipex->paths[flag]);
		pipex->paths[flag] = tmp;
		return (1);
	}
	tmp = ft_strdup(" ");
	return (0);
}

int	find_executable(t_pipex *pipex, int flag)
{
	char	**map;
	char	*cmd;
	char	**tmp;
	char	*buffer;
	int		i;

	map = ft_split(pipex->paths[flag], ' ');
	cmd = map[0];
	i = -1;
	if (ft_strstart(cmd, ".") || ft_strstart(cmd, "/"))
		return (search_relative(pipex, flag));
	while (pipex->all_paths[++i])
	{
		if (path_has_executable(pipex->all_paths[i], cmd))
		{
			tmp = ft_split(cmd, ' ');
			cmd = ft_strjoin("/", tmp[0]);
			buffer = ft_strjoin(pipex->all_paths[i], cmd);
			pipex->paths[flag] = buffer;
			ft_println("found command in %s", pipex->paths[flag]);
			return (clear_map(tmp), free(cmd), clear_map(map), 1);
		}
	}
	pipex->paths[flag] = NULL;
	return (clear_map(map), 0);
}
