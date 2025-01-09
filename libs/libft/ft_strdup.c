/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:30:05 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:30:07 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*target;

	target = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!target)
		return (NULL);
	ft_strlcpy(target, src, ft_strlen(src) + 1);
	return (target);
}
