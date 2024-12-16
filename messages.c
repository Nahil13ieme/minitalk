/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:08:32 by nbenhami          #+#    #+#             */
/*   Updated: 2024/11/29 08:12:54 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * I need to convert str to bytes. I'll put them in a int array then i'll send them via kill(pid, sig);
 * I'll send them through packets so the server wont be overflowed by huge packets coming
 * I send the last NULL byte too as a end signal receiver.
 * ((((unsigned char)(str[i] >> j)) & 1)) == 0x0 & 1 == 0 | 0x1 & 1 = 1. We use binary operation here
 * to know if each bytes of str[i] is 1 or 0. ">>" operands checks the bytes.
*/

int	stop = 0;

static void	sig_handler(int	signum)
{
	write(1, "test\n", 5);
	if (signum == SIGUSR1)
		stop = 1;
}

void	ft_strtobyte(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i <= ft_strlen(str))
	{
		j = 8;
		while (j-- >= 0)
		{
			usleep(50);
			if ((((unsigned char)(str[i] >> j)) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
		}
		while(!stop)
			if (signal(SIGUSR1, sig_handler) == SIG_ERR)
				return ;
		stop = 0;
		i++;
	}
}

static void	ft_send_pid(int pid)
{
	int my_pid;
	int	j;

	my_pid = getpid();
	j = (sizeof(int) * 8) - 1;
	while (j >= 0)
	{
		usleep(10);
		if ((((unsigned char)(my_pid >> j)) & 1))
			kill(pid, SIGUSR1);
		else if (!((unsigned char)(my_pid >> j) & 1))
			kill(pid, SIGUSR2);
		j--;
	}
}

void	send_message(int pid, char *str)
{
	ft_send_pid(pid);
	while (!stop)
	{
		if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		{
			printf("ERROR: Could not set signal handler\n");
			return ;
		}
	}
	ft_strtobyte(pid, str);
}
