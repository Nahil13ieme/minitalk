/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:09:50 by nbenhami          #+#    #+#             */
/*   Updated: 2025/03/01 20:07:05 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_buffer	g_buffer;

void	clear_buffer(void)
{
	free(g_buffer.str);
	g_buffer.buffer_size = 0;
	g_buffer.received_size = 0;
	g_buffer.bits = 0;
	g_buffer.index = 0;
	g_buffer.str = NULL;
}

void	init_buffer(void)
{
	g_buffer.buffer_size = 0;
	g_buffer.bits = 0;
	g_buffer.index = 0;
	g_buffer.str = NULL;
}

int	main(void)
{
	printf("Server PID: %d\n", getpid());
	init_buffer();
	my_signal(SIGUSR1, handler, 1);
	my_signal(SIGUSR2, handler, 1);
	while (1)
		pause();
	return (0);
}
