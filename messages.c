/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:08:32 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/31 14:54:46 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_strtobyte(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i <= ft_strlen(str))
	{
		j = 8;
		while (--j >= 0)
		{
			usleep(100);
			if ((((unsigned char)(str[i] >> j)) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
		}
		i++;
	}
}

void	send_message(int pid, char *str)
{
	ft_strtobyte(pid, str);
}
