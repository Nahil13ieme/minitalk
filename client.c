/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 07:35:06 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/31 15:08:58 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (ft_printf("client [PID] [\"MESSAGE\"]\n"), 1);
	else if (!check_atoi(argv[1]))
		return (ft_printf("client [PID] <-- DIGIT ONLY [\"MESSAGE\"]\n"), 1);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
