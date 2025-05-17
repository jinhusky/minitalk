/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:48:30 by kationg           #+#    #+#             */
/*   Updated: 2024/11/25 19:39:45 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The memmove function is used in C to copy a block of memory from 
//one location to another, handling the case where the source 
//and destination memory areas might overlap. How it works is that it will 
//first check if src address is smaller than dest is so copy from behind
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dest && dest < src + n)
	{
		while (i < n)
		{
			((unsigned char *)dest)[n - 1 - i]
				= ((unsigned char *)src)[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    //char str[] = "Hello, World!";  // Initialize a string
	
	char *str = NULL;
    ft_memmove(str + 7, str, 5);
	//memmove(str+7, str, 5);
    str[12] = '\0';

    printf("Resulting string: %s\n", str);

    return 0;
}
*/
