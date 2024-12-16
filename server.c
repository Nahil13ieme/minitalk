/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 07:34:59 by nbenhami          #+#    #+#             */
/*   Updated: 2024/11/29 08:09:57 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_buffer *buffer;

/*
 * I need to redo the functions.
 * I need to ft_strjoin() every character to the final string cause subject said :
 *		Une fois la chaîne entièrement reçue, le serveur doit l’afficher.
 * Then write it. I'll link my libft and my ft_printf to the project to remove the utils.
 * And the project should be done ? --> 28/11 im not okay on how the project is working. Gonna redo it
 * sig_handler() -> First 32 bits are for PID then i do a handcheck
 * 
*/


/* sig_handler(int signum)
 * Receiving PID first to get the client_pid to assure we can handcheck
 * handcheck
 * Add bits to *str
*/
void	sig_handler(int	signum)
{
	// new
	if (buffer->client_pid == 0)
	{
		if(signum == SIGUSR1)
			buffer->received_byte |= (1 << (31 - buffer->bits));
		buffer->bits++;
		if (buffer->bits == 31)
		{
			buffer->client_pid = buffer->received_byte;
			buffer->received_byte = 0;
			usleep(100);
			kill(buffer->client_pid, SIGUSR1);
		}
	}
	else
	{
		if(signum == SIGUSR1)
			buffer->received_byte |= (1 << (7 - buffer->bits));
		buffer->bits++;		
		if (buffer->bits == 8)
		{
			usleep(100);
			printf("received_byte = %c\n", buffer->received_byte);
			if(buffer->received_byte == 0)
				printf("%d : %s\n", buffer->client_pid, buffer->str);
			else
				buffer->str = ft_strjoin(buffer->str, (char)buffer->received_byte);
			buffer->received_byte = 0;
			kill(buffer->client_pid, SIGUSR1);
		}
	}
}

void	init_buffer()
{
	buffer->bits = 0;
	buffer->received_byte = 0;
	buffer->client_pid = 0;
	buffer->str = NULL;
}

int	main(void)
{
	buffer = malloc(sizeof(t_buffer));
	init_buffer();
	printf("SERVER PID = %d\n", getpid());
	while(1)
	{
		if(signal(SIGUSR1, sig_handler) == SIG_ERR)
		{
			printf("ERROR received \n");
			return(EXIT_FAILURE);
		}
		else if (signal(SIGUSR2, sig_handler) == SIG_ERR)
		{
			return(EXIT_FAILURE);	
			printf("ERROR received \n");
		}
	}
	return (0);
}