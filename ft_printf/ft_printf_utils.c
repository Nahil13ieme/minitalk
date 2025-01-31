/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:52:26 by nbenhami          #+#    #+#             */
/*   Updated: 2024/11/20 21:17:46 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

static int	ft_putbase(char *base, unsigned long long n, int is_signed, int fd)
{
	char				c;
	int					count;
	unsigned long long	base_len;

	if (!ft_is_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	count = 0;
	if (is_signed && (long long)n < 0)
	{
		write(fd, "-", 1);
		n = -(long long)n;
		count++;
	}
	if (n >= base_len)
		count += ft_putbase(base, n / base_len, is_signed, fd);
	c = base[n % base_len];
	write(fd, &c, 1);
	return (count + 1);
}

static int	ft_putbase_x(char *base, int n, int fd)
{
	unsigned int	abs_n;
	int				base_len;
	char			c;
	int				count;

	if (!ft_is_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	count = 0;
	abs_n = (unsigned int)n;
	if (abs_n >= (unsigned int)base_len)
		count += ft_putbase_x(base, abs_n / base_len, fd);
	c = base[abs_n % base_len];
	write(fd, &c, 1);
	return (count + 1);
}

static int	ft_putpointer(void *ptr, int fd)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	if (address == 0)
		return (ft_putstr("(nil)", fd));
	count = 0;
	count += ft_putchar('0', fd);
	count += ft_putchar('x', fd);
	count += ft_putbase("0123456789abcdef", address, 0, fd);
	return (count);
}

int	ft_check_format(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr((char *)va_arg(args, char *), 1));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(args, int), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putbase("0123456789", (int)va_arg(args, int), 1, 1));
	else if (c == 'u')
		return (ft_putbase("0123456789",
				(unsigned int)va_arg(args, unsigned int), 0, 1));
	else if (c == 'x')
		return (ft_putbase_x("0123456789abcdef", (int)va_arg(args, int), 1));
	else if (c == 'X')
		return (ft_putbase_x("0123456789ABCDEF", (int)va_arg(args, int), 1));
	else if (c == 'p')
		return (ft_putpointer((void *)va_arg(args, void *), 1));
	else if (c == '%')
		return (ft_putchar('%', 1));
	return (0);
}
