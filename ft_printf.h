/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:21:56 by cfranco-          #+#    #+#             */
/*   Updated: 2023/11/02 15:25:49 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_putchar(char c);
int	ft_putstr(char *s);
int ft_putnbr(int n);
int	ft_ishexaup(unsigned int n);
int	ft_ishexalow(unsigned int n);
int	ft_isunsigned(unsigned int n);
int	ft_check(const char *s, int i, va_list args);
int	ft_printf(const char *s, ...);
int	ft_ispoint(unsigned long long n, int control);

#endif