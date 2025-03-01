/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:24:02 by nbenhami          #+#    #+#             */
/*   Updated: 2025/03/01 20:40:55 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_sig(int pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		perror("kill failed");
		exit(EXIT_FAILURE);
	}
}

static void	handle_signal(void)
{
	int	ack;

	ack = 0;
	g_acknowledgment = 0;
	while (!g_acknowledgment)
	{
		if (ack > 500)
			break ;
		ack++;
		usleep(1);
	}
	g_acknowledgment = 0;
}

void	send_int(int pid, int len)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (((len >> i) & 1))
			send_sig(pid, SIGUSR1);
		else
			send_sig(pid, SIGUSR2);
		handle_signal();
		i--;
	}
}

void	send_string(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((message[i] >> (7 - j)) & 1)
				send_sig(pid, SIGUSR1);
			else
				send_sig(pid, SIGUSR2);
			handle_signal();
			j++;
		}
		i++;
	}
}
