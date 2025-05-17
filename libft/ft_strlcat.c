/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:44:25 by kationg           #+#    #+#             */
/*   Updated: 2024/11/23 18:22:45 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//the size is the total size of string you want to create. If size is
//smaller than dest buffer that means that the buffer is too small
//to hold the result. 
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	if (size == 0 && (!dest || !src))
		return (0);
	i = 0;
	length = ft_strlen(dest);
	if (size <= length)
	{
		return (ft_strlen(src) + size);
	}
	while ((length + i) < (size - 1) && src[i] != '\0')
	{
		dest[length + i] = src[i];
		i++;
	}
	dest[length + i] = '\0';
	return (length + ft_strlen(src));
}
