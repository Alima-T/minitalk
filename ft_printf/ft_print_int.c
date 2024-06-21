/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:26:24 by aokhapki          #+#    #+#             */
/*   Updated: 2024/04/27 19:48:27 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(long n, int base)
{
	int		ct;
	char	*chars;

	chars = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_int(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_ch(chars[n]));
	else
	{
		ct = ft_print_int(n / base, base);
		return (ct + ft_print_int(n % base, base));
	}
}
