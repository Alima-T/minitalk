/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:26:24 by aokhapki          #+#    #+#             */
/*   Updated: 2024/04/27 19:53:18 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ch(char ch)
{
	int	result;

	result = write(1, &ch, 1);
	if (result < 0)
		return (-1);
	return (result);
}
