/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:50:59 by kationg           #+#    #+#             */
/*   Updated: 2024/11/23 18:14:24 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*buffer;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	ptr = lst;
	new_lst = NULL;
	while (ptr)
	{
		buffer = ft_lstnew(f(ptr -> content));
		if (!buffer)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, buffer);
		ptr = ptr -> next;
	}
	return (new_lst);
}
