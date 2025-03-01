/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:09:54 by nbenhami          #+#    #+#             */
/*   Updated: 2025/03/01 20:33:30 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t g_acknowledgment = 0;

static int	is_digit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

static void	invalid_format(char *name, char *format)
{
	write(2, "Invalid format: ", 16);
	write(2, name, ft_strlen(name));
	write(2, format, ft_strlen(format));
	exit(EXIT_FAILURE);
}

static void	handle_acknowledgment(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
		g_acknowledgment = 1;
	else if (sig == SIGUSR2)
	{
		write(2, "Message received\n", 17);
		exit(EXIT_SUCCESS);
	}
}

static void	send_message(int pid, char *message)
{
	send_int(pid, ft_strlen(message));
	send_string(pid, message);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !is_digit(argv[1]))
		invalid_format(argv[0], "FORMAT : <pid> <message>");
	if (ft_strlen(argv[2]) == 0)
	{
		write(2, "Message is empty\n", 17);
		exit(EXIT_FAILURE);
	}
	my_signal(SIGUSR1, handle_acknowledgment, 0);
	my_signal(SIGUSR2, handle_acknowledgment, 0);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}