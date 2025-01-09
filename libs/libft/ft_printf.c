/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:27:11 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 13:17:04 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_args(const char *str, va_list args)
{
	int	current_size;

	current_size = 0;
	if (str[0] == 'c')
		current_size += handle_char(args);
	else if (str[0] == '%')
		current_size += handle_perc(args);
	else if (str[0] == 's')
		current_size += handle_stri(args);
	else if (str[0] == 'p')
		current_size += handle_ptrs(args);
	else if (str[0] == 'd' || str[0] == 'i')
		current_size += handle_nbrs(args);
	else if (str[0] == 'u')
		current_size += handle_unbr(args);
	else if (str[0] == 'x')
		current_size += handle_hexl(args);
	else if (str[0] == 'X')
		current_size += handle_hexu(args);
	return (current_size);
}

int	ft_println(const char *str, ...)
{
	int		str_size;
	int		index;
	va_list	args;

	va_start(args, str);
	index = -1;
	str_size = 0;
	if (ft_strchr(str, '%') == NULL)
	{
		ft_printf("\n");
		return (ft_putstr_fd((char *)str, STANDARD_OUTPUT_FD), ft_strlen(str));
	}
	while (str[++index])
	{
		if (str[index] == '%')
			str_size += handle_args(&str[++index], args);
		else
		{
			ft_putchar_fd(str[index], STANDARD_OUTPUT_FD);
			++str_size;
		}
	}
	ft_printf("\n");
	return (str_size + 1);
}

int	ft_printf(const char *str, ...)
{
	int		str_size;
	int		index;
	va_list	args;

	va_start(args, str);
	index = -1;
	str_size = 0;
	if (ft_strchr(str, '%') == NULL)
		return (ft_putstr_fd((char *)str, STANDARD_OUTPUT_FD), ft_strlen(str));
	while (str[++index])
	{
		if (str[index] == '%')
			str_size += handle_args(&str[++index], args);
		else
		{
			ft_putchar_fd(str[index], STANDARD_OUTPUT_FD);
			++str_size;
		}
	}
	return (str_size);
}
