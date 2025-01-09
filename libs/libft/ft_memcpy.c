/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:24:11 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:24:13 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dest && !src)
		return (NULL);
	tmp = (unsigned char *)dest;
	while (n-- != 0)
	{
		*(unsigned char *)tmp = *(unsigned char *)src;
		++tmp;
		++src;
	}
	return (dest);
}
