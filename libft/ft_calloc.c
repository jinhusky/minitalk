/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:08:14 by kationg           #+#    #+#             */
/*   Updated: 2024/11/23 19:50:05 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//used to allocate an array of elements and initialize to 0.
//calloc is slower than malloc as it initilizes the  mem.
void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (n == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return ((void *)ptr);
	}
	i = n * size;
	if (n > (size_t) -1 / size)
		return (NULL);
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, i);
	return ((void *)ptr);
}
