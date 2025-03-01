/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:09:47 by nbenhami          #+#    #+#             */
/*   Updated: 2025/03/01 20:42:06 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <err.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	int		buffer_size;
	int		received_size;
	int		bits;
	int		index;
	char	*str;
}	t_buffer;

extern volatile sig_atomic_t	g_acknowledgment;
extern t_buffer					g_buffer;

void	handler(int signo, siginfo_t *info, void *context);
void	my_signal(int sig, void *handler, int b_siginfo);
void	send_int(int pid, int len);
void	send_string(int pid, char *message);
void	clear_buffer(void);
void	ft_putnbr_fd(int n);
int		ft_atoi(char *str);
int		ft_strlen(char *str);

#endif