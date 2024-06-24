/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:57:44 by aokhapki          #+#    #+#             */
/*   Updated: 2024/06/24 23:25:10 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	negative_sign;

	number = 0;
	negative_sign = 1;
	while (*str != '\0' && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str != '\0' && (*str == '+' || *str == '-'))
		if (*str++ == '-')
			negative_sign *= -1;
	number = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * negative_sign);
}

void	send_symbol(pid_t pid, char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (ch & (1 << i--))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(300);
	}
}

void	send_string(pid_t pid, char *text)
{
	while (*text)
	{
		send_symbol(pid, *text++);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		write(2, "Use: ./client <PID> <your message>\n", 36);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
