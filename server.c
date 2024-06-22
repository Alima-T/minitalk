/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:21:33 by aokhapki          #+#    #+#             */
/*   Updated: 2024/06/22 19:06:23 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_catch(int signal_type)
{
	static char	ch;
	static int	i;

	if (i == 0)
		ch = 0;
	ch |= (signal_type == SIGUSR2);
	i++;
	if (i == 8)
	{
		write(1, &ch, 1);
		i = 0;
	}
	else
	{
		ch <<= 1;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID is: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_catch);
		signal(SIGUSR2, signal_catch);
		pause();
	}
	return (0);
}
