/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:13:44 by kationg           #+#    #+#             */
/*   Updated: 2024/11/23 18:16:26 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//search for a specific byte within a block of memory.Return a pointer to 
//the first occurance of specified byte of NULL if not found within n number
//of bytes
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char) c)
			return (&((unsigned char *)str)[i]);
		i++;
	}
	return (NULL);
}
