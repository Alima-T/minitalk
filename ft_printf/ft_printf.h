/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:26:24 by aokhapki          #+#    #+#             */
/*   Updated: 2024/04/27 21:18:39 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// # mandatory_functions
int	ft_printf(const char *s, ...);
int	ft_print_format(char ch, va_list args);
int	ft_print_ch(char ch);
int	ft_print_str(char *str);
int	ft_print_percent(void);
int	ft_print_int(long n, int base);
int	ft_print_hex_upper(long n, int base);
int	ft_print_ptr(unsigned long long n);
#endif
