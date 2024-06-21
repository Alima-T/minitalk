/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:26:24 by aokhapki          #+#    #+#             */
/*   Updated: 2024/04/27 21:26:26 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}

int	ft_print_format(char ch, va_list args)
{
	int	ct;

	ct = 0;
	if (ch == 'c')
		ct = ct + ft_print_ch(va_arg(args, int));
	else if (ch == 's')
		ct = ct + ft_print_str(va_arg(args, char *));
	else if (ch == 'd' || ch == 'i')
		ct = ct + ft_print_int((long)(va_arg(args, int)), 10);
	else if (ch == 'u')
		ct = ct + ft_print_int((long)(va_arg(args, unsigned int)), 10);
	else if (ch == 'x')
		ct = ct + ft_print_int((long)(va_arg(args, unsigned int)), 16);
	else if (ch == 'X')
		ct = ct + ft_print_hex_upper((long)(va_arg(args, unsigned int)), 16);
	else if (ch == 'p')
	{
		write(1, "0x", 2);
		ct += 2 + ft_print_ptr((long long)(va_arg(args, unsigned long long)));
	}
	else if (ch == '%')
		ct = ct + ft_print_percent();
	else
		ct = ct + write(1, &ch, 1);
	return (ct);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ct;

	va_start(args, format);
	ct = 0;
	while (*format)
	{
		if (*format == '%')
			ct = ct + ft_print_format(*(++format), args);
		else
			ct = ct + write(1, format, 1);
		++format;
	}
	va_end(args);
	return (ct);
}

// # include <stdio.h>

// int main (void)
// {
// 	int ct;
// 	char ch;
// 	ch = 37;

// 	ct = ft_printf(" %%Ch %%%c\n S %s\n D%d\n I %i\n HL %x\n HU %X\n P%p\n UI %u
//\n %p\n %p\n", 'a',"Hello", -11, 11, -11, -11, &ch, 100, LONG_MIN, LONG_MAX);
// 	ft_printf ("The ct of chars in implemented by me ft_printf is %d\n", ct);
// 	printf ("***********************************************\n");
// 	printf(" %%Ch %%%c\n S %s\n D%d\n I %i\n HL %x\n HU %X\n P%p\n UI %u
//\n %p\n %p\n", 'a',"Hello", -11, 11, -11, -11, &ch, 100, LONG_MIN, LONG_MAX);
// 	printf ("The ct of chars in original printf is %d\n", ct);
// 	return (0);
// }

// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.