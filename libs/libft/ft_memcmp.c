/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:23:59 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:24:01 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ss1[i] != (unsigned char)ss2[i])
			return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
		++i;
	}
	return (0);
}
