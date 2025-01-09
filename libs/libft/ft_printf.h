/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:27:26 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 08:39:55 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STANDARD_OUTPUT_FD 1

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
int		ft_println(const char *str, ...) __attribute__((format(printf, 1, 2)));
int		handle_char(va_list args);
int		handle_perc(va_list args);
int		handle_stri(va_list args);
int		handle_ptrs(va_list args);
int		handle_nbrs(va_list args);
int		handle_unbr(va_list args);
int		handle_hexl(va_list args);
int		handle_hexu(va_list args);
char	*ft_uitoa(unsigned int n);
#endif
