/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:42:53 by kationg           #+#    #+#             */
/*   Updated: 2024/11/20 17:30:17 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//find the first occurance of a substring within a string. It limits the number
//of characters from the beginning of big string.
char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && n == 0)
		return (NULL);
	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] && little[j] && (i + j) < n)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
