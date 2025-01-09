/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_hexa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:27:58 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:27:59 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hexa(unsigned int num, int is_upper)
{
	int	size;

	size = 0;
	if (num >= 16)
	{
		size += print_hexa(num / 16, is_upper);
		size += print_hexa(num % 16, is_upper);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', STANDARD_OUTPUT_FD);
		else
		{
			if (is_upper)
				ft_putchar_fd(num - 10 + 'A', STANDARD_OUTPUT_FD);
			else
				ft_putchar_fd(num - 10 + 'a', STANDARD_OUTPUT_FD);
		}
		++size;
	}
	return (size);
}

int	handle_hexl(va_list args)
{
	return (print_hexa(va_arg(args, unsigned int), 0));
}

int	handle_hexu(va_list args)
{
	return (print_hexa(va_arg(args, unsigned int), 1));
}
