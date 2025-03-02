/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:56:37 by nbenhami          #+#    #+#             */
/*   Updated: 2025/03/02 13:01:34 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_str_size(int signo, siginfo_t *info)
{
	g_buffer.buffer_size = (g_buffer.buffer_size << 1) | (signo == SIGUSR1);
	g_buffer.bits++;
	if (g_buffer.bits == 32)
	{
		g_buffer.bits = 0;
		g_buffer.received_size = 1;
		g_buffer.str = malloc(sizeof(char *) * (g_buffer.buffer_size + 1));
	}
	kill(info->si_pid, SIGUSR1);
}

static void	handle_str(int signo, siginfo_t *info)
{
	g_buffer.str[g_buffer.index] = (g_buffer.str[g_buffer.index] << 1)
		| (signo == SIGUSR1);
	g_buffer.bits++;
	if (g_buffer.bits == 8)
	{
		g_buffer.index++;
		g_buffer.bits = 0;
	}
	if (g_buffer.index == g_buffer.buffer_size)
	{
		g_buffer.str[g_buffer.buffer_size] = '\0';
		write(1, "\033[0;34m", 8);
		write(1, "client_", 8);
		ft_putnbr_fd(info->si_pid);
		write(1, "\033[0;32m»", 9);
		write(1, g_buffer.str, g_buffer.buffer_size);
		write(1, "\n", 1);
		clear_buffer();
		kill(info->si_pid, SIGUSR2);
	}
	kill(info->si_pid, SIGUSR1);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (signo == SIGUSR1 || signo == SIGUSR2)
	{
		if (!g_buffer.received_size)
			handle_str_size(signo, info);
		else
			handle_str(signo, info);
	}
	else if (signo == SIGINT)
	{
		write(1, "\n\033[0;31mServer stopped\n", 22);
		write(1, "\n", 1);
		clear_buffer();
		exit(EXIT_SUCCESS);
	}
}
