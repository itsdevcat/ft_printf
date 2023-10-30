/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:03:56 by cfranco-          #+#    #+#             */
/*   Updated: 2023/10/24 11:30:17 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const char unsigned	*p1;
	const char unsigned	*p2;
	size_t				i;

	p1 = (const char unsigned *)ptr1;
	p2 = (const char unsigned *)ptr2;
	i = 0;
	while (i < n)
	{
		if (p1[i] == p2[i])
			i++;
		else
			return (p1[i] - p2[i]);
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_memcmp("Hey", "Hello", 2));
	return (0);
}*/

/* The  memchr()  and memrchr() functions return a pointer to the matching
 byte or NULL if the character does not occur in the given memory area. */
