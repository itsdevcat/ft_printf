/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:18:32 by cfranco-          #+#    #+#             */
/*   Updated: 2023/10/26 16:26:36 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 1;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
		{
			word++;
		}
		i++;
	}
	return (word);
}

static int	word_size(const char *s, int i, char c)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	words = countwords(s, c);
	new = (char **)malloc((words + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (s[i] && j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		new[j] = ft_substr(s, i, word_size(s, i, c));
		i = i + word_size(s, i, c);
		j++;
	}
	new[words] = NULL;
	return (new);
}
/*
int main()
{
	char **strings = ft_split("      split       this for   me  !       ", ' ');

	while (*strings)
    {
        printf("%s\n", *strings);
        strings++;
    }
	return (0);
}*/

/*i += word_size(s, i, c); - e pra andar na string, passar a palavra q acabamos de copiar.*/
//new[words] = NULL; estamos a colocar null no final da matriz
