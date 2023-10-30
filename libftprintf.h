/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:21:56 by cfranco-          #+#    #+#             */
/*   Updated: 2023/10/30 18:20:16 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF
# define LIBFTPRINTF

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

void	ft_putchar(char c);
void	ft_ishexaup(unsigned int n);
void	ft_ishexalow(unsigned int n);
void	ft_isunsigned(unsigned int n);
void	ft_check(const char *s, int i, va_list args);
void	ft_printf(const char *s, ...);

#endif