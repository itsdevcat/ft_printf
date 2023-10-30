/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:35:49 by cfranco-          #+#    #+#             */
/*   Updated: 2023/10/30 18:19:57 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_ishexaup(unsigned int n)
{
	char *base;
	
	base = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_ishexaup(n / 16);
		n = n % 16;
	}
	ft_putchar_fd(base[n], 1);
}

void	ft_ishexalow(unsigned int n)
{
	char *base;
	
	base = "0123456789abcdef";
	if (n > 15)
	{
		ft_ishexalow(n / 16);
		n = n % 16;
	}
	ft_putchar_fd(base[n], 1);
}

void	ft_isunsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_isunsigned(n / 10);
		n = n % 10;
	}
	ft_putchar_fd(n + '0', 1);
}

void	ft_check(const char *s, int i, va_list args)
{	
	if (s[i + 1] == 'c')
	{
		ft_putchar(va_arg(args, int));
	}
	else if (s[i + 1] == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (s[i + 1] == 'p')
	{
		write (1, "0x", 2);
		ft_ishexalow(va_arg(args, unsigned int));
	}
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
	}
	else if (s[i + 1] == 'u')
	{
		ft_isunsigned(va_arg(args, unsigned int));
	}
	else if (s[i + 1] == 'x')
	{
		ft_ishexalow(va_arg(args, unsigned int));
	}
	else if (s[i + 1] == 'X')
	{
		ft_ishexaup(va_arg(args, unsigned int));
	}
	else if (s[i + 1] == '%')
	{
		write(1, "%", 1);
	}	
}

void	ft_printf(const char *s, ...)
{
	int	i;
	
	va_list args;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
			ft_check(s, i, args);
	} 
}