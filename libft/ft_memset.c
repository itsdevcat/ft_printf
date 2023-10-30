/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:06:42 by cfranco-          #+#    #+#             */
/*   Updated: 2023/10/24 12:21:34 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)ptr;
	i = 0;
	while (i < n)
	{
		str[i] = value;
		i++;
	}
	return (ptr);
}

/*int	main(void)
{
	char alphabet[] = "123456789";

	printf("Before memset: %s\n", alphabet);
	ft_memset(alphabet, '*', 5);
	printf("After memset: %s\n", alphabet);
	return (0);
}*/

/*The  memset()  function  fills  the  first  n  bytes of the memory area
pointed to by s with the constant byte c.
  Returns a pointer to the memory area s.
*/
