/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:21:47 by aokhapki          #+#    #+#             */
/*   Updated: 2024/04/27 17:09:53 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upper(long n, int base)
{
	int		ct;
	char	*chars;

	chars = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_hex_upper(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_ch(chars[n]));
	else
	{
		ct = ft_print_hex_upper(n / base, base);
		return (ct + ft_print_hex_upper(n % base, base));
	}
}
