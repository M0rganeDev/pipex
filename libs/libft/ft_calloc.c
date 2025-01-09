/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:17:17 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:17:19 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*val;
	size_t	total;

	total = count * size;
	if ((count > 0) && (size > total / count))
		return (NULL);
	val = malloc(total);
	if (!val)
		return (NULL);
	ft_bzero(val, total);
	return (val);
}
