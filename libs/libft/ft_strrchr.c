/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:31:49 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:31:50 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	cc;

	res = NULL;
	cc = (char)c;
	while (*s)
	{
		if (*s == cc)
			res = (char *)s;
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (res);
}
