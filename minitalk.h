/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 07:28:43 by nbenhami          #+#    #+#             */
/*   Updated: 2025/01/31 15:08:25 by nbenhami         ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"

typedef struct s_buffer
{
	int				bits;
	int				received_byte;
	char			*str;
}	t_buffer;

int		ft_strlen(char *str);
int		check_atoi(char *str);
void	send_message(int pid, char *str);
int		receive_message(void);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, char c);

#endif