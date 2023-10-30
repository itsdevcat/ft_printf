/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco- <cfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:11:11 by cfranco-          #+#    #+#             */
/*   Updated: 2023/10/19 14:55:49 by cfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	print_content(void *content)
{
	printf("The content of the list is: %s\n", (char *)content);
}*/

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp->next)
	{
		(*f)(tmp->content);
		tmp = tmp->next;
	}
	(*f)(tmp->content);
}
/*
int	main(void)
{
	t_list *list = ft_lstnew(ft_strdup("Hello,"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("World!")));
	ft_lstiter(list, print_content);
	return (0);
}*/
//e importante criar um pointer tmp pra nao perdermos/alterarmos 
//o inicio da lista.
// while (tmp->next) significa enquanto tmp tenha algum node a frente.
//voltamos a chamar a funcao caso a lista so tenha um elemento, ou pra 
// aplicarmos a funcao ao ultimo, se tiver mais do q um.