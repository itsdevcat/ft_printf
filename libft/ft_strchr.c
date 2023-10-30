/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:18:17 by cfranco-          #+#    #+#             */
/*   Updated: 2023/10/24 12:43:35 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "Hello, pessoal.";
	char	*result;
	int		find;

	find = 'e';

	result = ft_strchr(str, find);

	if (result)
		printf("Character was found on the index number: %d\n", find);
	else
		printf("Character not found.\n");
	return (0);
}*/
/*return ((char *)s + i);: Esta expressão está correta e é usada para retornar 
um ponteiro para a posição de memória dentro da string s onde foi encontrado o caractere 
correspondente a (char)c. O + i está adicionando um deslocamento (offset) a partir do 
início da string s, apontando diretamente para a posição onde o caractere foi encontrado. 
Isso é necessário porque estamos trabalhando com um ponteiro para caracteres.*/