/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:08:32 by kationg           #+#    #+#             */
/*   Updated: 2024/11/23 20:04:24 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !(new))
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		ptr = ft_lstlast(*lst);
		ptr -> next = new;
	}
}
