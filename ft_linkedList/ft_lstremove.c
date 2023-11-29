/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:03:00 by psalame           #+#    #+#             */
/*   Updated: 2023/11/29 15:15:27 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **lst, t_list *ele, void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (!lst || !ele)
		return ;
	prev = NULL;
	current = *lst;
	while (current)
	{
		next = current->next;
		if (current == ele)
		{
			if (prev == NULL)
				*lst = next;
			else
				prev->next = next;
			ft_lstdelone(current, del);
			current = next;
		}
		else
			prev = current;
		current = next;
	}
}
