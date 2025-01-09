/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:31:19 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:31:20 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		current;

	current = 0;
	result = (char *)ft_calloc(sizeof(char), ft_strlen((char *)s) + 1);
	if (!result)
		return (NULL);
	while (*s != '\0')
	{
		result[current] = f(current, *s);
		++s;
		++current;
	}
	return (result);
}
