/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:24:36 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:24:37 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*c;
	size_t		index;

	if (!dest && !src)
		return (0);
	d = (char *)dest;
	c = (const char *)src;
	index = -1;
	if (d < c)
		while (++index < n)
			d[index] = c[index];
	else
		while (n-- > 0)
			d[n] = c[n];
	return (dest);
}
