/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:27:16 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 12:50:34 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// paths : the absolute path to both executables
// files : the input and output files, respectively
// env_path : $PATH
// all_paths : env_path but as an array of string
// for easy loop
typedef struct s_pipex
{
	char	*paths[2];
	char	*files[2];
	char	**all_paths;
	char	*env_path;
}	t_pipex;

// parse argv, return a t_pipex instance if everything works
// otherwise it returns null.
// everything is done on the stack if possible to avoid memory leaks
t_pipex	parse_argv(char **argv, char **env);

// look in the $PATH variable to look for the executable
int		path_has_executable(const char *path, const char *cmd);

// util methods to see if a string target start or end with a target
int		ft_strstart(const char *target, const char *needle);
int		ft_strend(const char *target, const char *end);

#endif
