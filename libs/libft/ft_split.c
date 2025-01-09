/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:29:06 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:29:15 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*populate(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	found;

	count = 0;
	found = 0;
	while (*str)
	{
		if (*str != c && !found)
		{
			found = 1;
			count++;
		}
		else if (*str == c)
			found = 0;
		str++;
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	reset(size_t *index, int *count, int *start_word)
{
	*index = 0;
	*count = 0;
	*start_word = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	index;
	int		count;
	int		start_word;

	reset(&index, &count, &start_word);
	res = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (index <= ft_strlen(s))
	{
		if (s[index] != c && start_word < 0)
			start_word = index;
		else if ((s[index] == c || index == ft_strlen(s)) && start_word >= 0)
		{
			res[count] = populate(s, start_word, index);
			if (!(res[count]))
				return (ft_free(res, count));
			start_word = -1;
			++count;
		}
		++index;
	}
	return (res);
}
