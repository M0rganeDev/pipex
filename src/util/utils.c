/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:48 by morgane           #+#    #+#             */
/*   Updated: 2025/01/15 11:57:59 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	clear_map(char **map)
{
	int	index;

	index = -1;
	while (map[++index])
		free(map[index]);
	free(map);
}

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

int	find_executable(t_pipex *pipex, int flag)
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
