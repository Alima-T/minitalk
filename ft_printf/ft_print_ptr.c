/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:22:29 by aokhapki          #+#    #+#             */
/*   Updated: 2024/04/27 19:50:46 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long n)
{
	int		ct;
	char	*chars;

	chars = "0123456789abcdef";
	if (n < 16)
	{
		ct = ft_print_ch(chars[n]);
		if (ct < 0)
			return (-1);
		else
			return (ct);
	}
	else
	{
		ct = ft_print_ptr(n / 16);
		return (ct + ft_print_ptr(n % 16));
	}
}
