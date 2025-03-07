/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:33:07 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:33:09 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	nb_size(unsigned long n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		++size;
	}
	return (size);
}

static void	iter_through_long(unsigned long n, char *buffer, size_t max)
{
	--max;
	while (n != 0)
	{
		buffer[max - 1] = (char)(n % 10) + '0';
		n /= 10;
		--max;
	}
}

char	*ft_ultoa(unsigned long n)
{
	char			*buffer;
	unsigned long	number;

	if (n == 0)
		return (ft_strdup("0"));
	number = n;
	buffer = (char *)malloc(sizeof(char) * (nb_size(number) + 1));
	if (!buffer)
		return (NULL);
	iter_through_long(number, buffer, nb_size(number) + 1);
	buffer[nb_size(number)] = '\0';
	return (buffer);
}
