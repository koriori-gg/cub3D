/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:29:16 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	ptr = ft_lstnew(f(lst->content));
	if (!ptr)
		return (NULL);
	cur = ptr;
	lst = lst->next;
	while (lst && cur)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (!cur->next)
			ft_lstclear(&ptr, del);
		cur = cur->next;
		lst = lst->next;
	}
	return (ptr);
}
