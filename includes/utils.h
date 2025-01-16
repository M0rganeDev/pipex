/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:58:13 by morgane           #+#    #+#             */
/*   Updated: 2025/01/16 13:30:31 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_pipex	t_pipex;

// free a malloc'd **char.
// no clue why this is not in libft.
void	clear_map(char **map);

// polite way to ask someone to STFU
void	pipe_down(t_pipex *pipex);

#endif
