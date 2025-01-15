/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:27:16 by morgane           #+#    #+#             */
/*   Updated: 2025/01/15 16:07:11 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "utils.h"
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

// paths : the absolute path to both executables
// files : the input and output files, respectively
// env_path : $PATH
// all_paths : env_path but as an array of string
// for easy loop
typedef struct s_pipex
{
	char	*paths[2];
	char	*files[2];
	char	**base_env;
	char	**base_argv;
	char	**all_paths;
	char	*env_path;
	int		pipes[2];
}	t_pipex;

// parse argv, return a t_pipex instance if everything works
// otherwise it returns null.
// everything is done on the stack if possible to avoid memory leaks
t_pipex	parse_argv(char **argv, char **env);

// wrapper to execute a program, 
// return a status code and write its output to output
int		exec_program(t_pipex *pipex, int flag);

// look in the $PATH variable to look for the executable
int		path_has_executable(const char *path, const char *cmd);

// util methods to see if a string target start or end with a target
int		ft_strstart(const char *target, const char *needle);
int		ft_strend(const char *target, const char *end);

#endif
