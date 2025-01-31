/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 07:34:59 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/31 15:12:09 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_buffer	*g_buffer;

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_buffer->received_byte |= (1 << (7 - g_buffer->bits));
	g_buffer->bits++;
	if (g_buffer->bits == 8)
	{
		if (g_buffer->received_byte == 0)
		{
			ft_printf("%s\n", g_buffer->str);
			free(g_buffer->str);
			g_buffer->str = NULL;
		}
		else
			g_buffer->str = ft_strjoin(g_buffer->str,
					(char)g_buffer->received_byte);
		g_buffer->received_byte = 0;
		g_buffer->bits = 0;
	}
}

void	init_buffer(void)
{
	g_buffer->bits = 0;
	g_buffer->received_byte = 0;
	g_buffer->str = NULL;
}

int	main(void)
{
	g_buffer = malloc(sizeof(t_buffer));
	init_buffer();
	ft_printf("SERVER PID = %d\n", getpid());
	while (1)
	{
		if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		{
			ft_printf("ERROR received \n");
			return (EXIT_FAILURE);
		}
		else if (signal(SIGUSR2, sig_handler) == SIG_ERR)
		{
			ft_printf("ERROR received \n");
			return (EXIT_FAILURE);
		}
	}
	if (g_buffer->str)
		free(g_buffer->str);
	free(g_buffer);
	return (0);
}
