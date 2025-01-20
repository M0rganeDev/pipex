/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:01:44 by morgane           #+#    #+#             */
/*   Updated: 2025/01/17 13:48:47 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"
#include <stdlib.h>

void	clear_map(char **map)
{
	int	index;

	index = -1;
	while (map[++index])
		free(map[index]);
	free(map);
}

void	pipe_down(t_pipex *pipex)
{
	close(pipex->channel[0]);
	close(pipex->channel[1]);
}
