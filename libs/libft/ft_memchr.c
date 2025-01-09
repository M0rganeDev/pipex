/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:23:47 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:23:49 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	while (size--)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		++s;
	}
	return ((void *)0);
}
