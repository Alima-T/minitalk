/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:09:34 by aokhapki          #+#    #+#             */
/*   Updated: 2024/04/27 19:44:21 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	ct;

	ct = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		if (ft_print_ch((int)*str) < 0)
			return (-1);
		ct++;
		str++;
	}
	return (ct);
}
