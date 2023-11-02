/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:35:49 by cfranco-          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:18 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ishexaup(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_ishexaup(n / 16);
		n = n % 16;
	}
	count += ft_putchar(base[n]);
	return (count);
}

int	ft_ishexalow(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_ishexalow(n / 16);
		n = n % 16;
	}
	count += ft_putchar(base[n]);
	return (count);
}

int	ft_isunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_isunsigned(n / 10);
		n = n % 10;
	}
	count += ft_putchar(n + '0');
	return (count);
}

int	ft_check(const char *s, int i, va_list args)
{
	int	count;

	count = 0;
	if (s[i + 1] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s[i + 1] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s[i + 1] == 'p')
		count += ft_ispoint(va_arg(args, unsigned long long), 1);
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s[i + 1] == 'u')
		count += ft_isunsigned(va_arg(args, unsigned int));
	else if (s[i + 1] == 'x')
		count += ft_ishexalow(va_arg(args, unsigned int));
	else if (s[i + 1] == 'X')
		count += ft_ishexaup(va_arg(args, unsigned int));
	else if (s[i + 1] == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!s)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		else
		{
			count += ft_check(s, i, args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
