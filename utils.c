/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:38:52 by cfranco-          #+#    #+#             */
/*   Updated: 2023/11/02 15:25:30 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		n = n % 10;
	}
	count += ft_putchar(n + '0');
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_ispoint(unsigned long long n, int control)
{
	char	*base;
	int		count;

	if (n == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count = 0;
	base = "0123456789abcdef";
	if (control == 1)
		count += ft_putstr("0x");
	if (n > 15)
	{
		count += ft_ispoint(n / 16, 0);
		n = n % 16;
	}
	count += ft_putchar(base[n]);
	return (count);
}