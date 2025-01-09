/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:22:36 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:22:37 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	nb_size(long n)
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

static long	gaset_absolute(long *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	return (0);
}

static void	iter_through_long(long n, char *buffer, size_t max, int sign)
{
	max -= sign;
	--max;
	if (sign)
		buffer[0] = '-';
	while (n != 0)
	{
		buffer[max - 1 + sign] = (char)(n % 10) + '0';
		n /= 10;
		--max;
	}
}

char	*ft_itoa(int n)
{
	char	*buffer;
	long	number;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	number = (long)n;
	sign = gaset_absolute(&number);
	buffer = (char *)malloc(sizeof(char) * (nb_size(number) + 1 + sign));
	if (!buffer)
		return (NULL);
	iter_through_long(number, buffer, nb_size(number) + 1 + sign, sign);
	buffer[nb_size(number) + sign] = '\0';
	return (buffer);
}
