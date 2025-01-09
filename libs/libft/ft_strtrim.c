/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:32:04 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:32:05 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_trimmable(char const *set, char str_chr)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == str_chr)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index_s1;
	int		index_s1_a;
	size_t	t_left;
	size_t	t_right;
	char	*result;

	if (ft_strlen((char *)s1) == 0)
		return (ft_strdup(""));
	index_s1 = -1;
	index_s1_a = ft_strlen((char *)s1);
	t_left = 0;
	t_right = 0;
	while (is_trimmable(set, s1[++index_s1]))
		++t_left;
	while (is_trimmable(set, s1[--index_s1_a]))
		++t_right;
	if ((int)(ft_strlen((char *)s1) - t_left - t_right) <= 0)
		return (ft_strdup(""));
	result = ft_substr(s1, t_left, ft_strlen((char *)s1) - t_left - t_right);
	if (result)
		result[ft_strlen((char *)result)] = '\0';
	return (result);
}
