/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:44:12 by kationg           #+#    #+#             */
/*   Updated: 2024/11/20 16:49:25 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//for n number of bytes, copy src into dest. Does not have 
//protection against null input. If there is overlap use memmove 
//Faster than memmove 
void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest_str)[i] = ((unsigned char *)src_str)[i];
		i++;
	}
	return (dest_str);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char *src = NULL; 
	char *dest = NULL; 
    //char dest[20];                 
	
    //ft_memcpy(dest, src, 20);
	memcpy(dest, src, 20);

	
    printf("Resulting string in dest: %s\n", dest);

    return 0;
}
*/
