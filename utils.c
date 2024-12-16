/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:07:26 by nbenhami          #+#    #+#             */
/*   Updated: 2024/11/26 01:19:50 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	check_atoi(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	n;
	int	sign;
	int	i;

	sign = 1;
	n = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	return (n);
}

char	*ft_strjoin(char *s1, char c)
{
	char			*array;
	unsigned int	size;
	int				i;
	int				j;

	if (!s1 && !c)
		return (NULL);
	if (!s1)
		size = 1;
	else
		size = ft_strlen(s1) + 1;
	array = (char *)malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if	(s1)
		while (s1[i])
			array[j++] = s1[i++];
	array[j] = c;
	array[size] = '\0';
	free(s1);
	return (array);
}
