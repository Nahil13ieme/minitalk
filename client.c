/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 07:35:06 by nbenhami          #+#    #+#             */
/*   Updated: 2024/11/28 11:18:24 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	//int	count = 0;

	if (argc != 3)
		return (printf("WRONG ARGUMENTS NUMBER : ./client [PID] [\"MESSAGE\"]\n"),-1);
	else if (!check_atoi(argv[1]))
		return (printf("WRONG ARGUMENT TYPE : ./client [PID] <-- DIGIT ONLY [\"MESSAGE\"]\n"),-1);
	// if ((count = send_message(6546, argv[2])) != ft_strlen(argv[2]))
	// 	return (printf("ERRORS : Sent %d but server received %d.", ft_strlen(argv[2]), count),-1);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}