/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 07:28:43 by nbenhami          #+#    #+#             */
/*   Updated: 2024/11/29 07:47:54 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_buffer
{
	int				bits;
	int				client_pid;
	int				received_byte;
	char			*str;
	struct s_buffer	*next;
}					t_buffer;

int		ft_strlen(char *str);
int		check_atoi(char *str);
void	send_message(int pid, char *str);
int		receive_message(void);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, char c);

#endif