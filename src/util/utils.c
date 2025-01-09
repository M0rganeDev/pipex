/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:48 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 12:59:28 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
