/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:21:27 by kationg           #+#    #+#             */
/*   Updated: 2024/11/23 18:26:17 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copies src into dest for size - 1 number of bytes. returns the 
//length of src even if fails and always null terminate dest.
//It is safer than strcpy as it prevent buffer overflows and 
//strncpy because it guarantees null-termination
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";  
    char dest[20];                 

    size_t result = ft_strlcpy(dest, src, sizeof(dest));

    printf("Result of ft_strlcpy: %zu\n", result);  
    printf("Destination string: %s\n", dest);   

    return 0;
}*/
