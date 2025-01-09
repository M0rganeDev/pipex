/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_basics.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:27:40 by morgane           #+#    #+#             */
/*   Updated: 2024/12/12 09:27:41 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list args)
{
	ft_putchar_fd((char)va_arg(args, int), STANDARD_OUTPUT_FD);
	return (1);
}

int	handle_perc(va_list args)
{
	(void)args;
	ft_putchar_fd('%', STANDARD_OUTPUT_FD);
	return (1);
}

int	handle_stri(va_list args)
{
	char	*to_print;

	to_print = va_arg(args, char *);
	if (to_print == NULL)
	{
		ft_putstr_fd("(null)", STANDARD_OUTPUT_FD);
		return (6);
	}
	ft_putstr_fd(to_print, STANDARD_OUTPUT_FD);
	return (ft_strlen(to_print));
}

int	handle_nbrs(va_list args)
{
	char	*to_print;
	int		str_size;

	to_print = ft_itoa(va_arg(args, int));
	str_size = ft_strlen(to_print);
	ft_putstr_fd(to_print, STANDARD_OUTPUT_FD);
	free(to_print);
	return (str_size);
}
