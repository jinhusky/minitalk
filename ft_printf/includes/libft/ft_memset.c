/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:07:19 by kationg           #+#    #+#             */
/*   Updated: 2024/11/20 16:45:14 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// fill in constent character c into the address pointed 
//by str for n bytes. Returning the address of original 
//str. Does not need protection 
void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (str);
}
/*
int main() {
    char str[10] = "abcdefghi"; // Initialize a string

    // Use ft_memset to fill the first 5 characters with 'X'
    ft_memset(str, 'X', 5);

    // Print the result
    printf("Resulting string: %s\n", str);

    return 0;
}*/
