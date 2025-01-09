/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_complex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:21:23 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:21:29 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdint.h"

static int	print_hexa(unsigned long num)
{
	int	size;

	size = 0;
	if (num >= 16)
	{
		size += print_hexa(num / 16);
		size += print_hexa(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', STANDARD_OUTPUT_FD);
		else
			ft_putchar_fd(num - 10 + 'a', STANDARD_OUTPUT_FD);
		++size;
	}
	return (size);
}

int	handle_ptrs(va_list args)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	if (ptr == 0)
		return (ft_putstr_fd("(nil)", STANDARD_OUTPUT_FD), ft_strlen("(nil)"));
	ft_putstr_fd("0x", STANDARD_OUTPUT_FD);
	return (print_hexa(ptr) + 2);
}

int	handle_unbr(va_list args)
{
	unsigned int	value;
	unsigned int	str_size;
	char			*to_print;

	value = va_arg(args, unsigned int);
	to_print = ft_uitoa(value);
	ft_putstr_fd(to_print, STANDARD_OUTPUT_FD);
	str_size = ft_strlen(to_print);
	free(to_print);
	return (str_size);
}
