/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:51:11 by kationg           #+#    #+#             */
/*   Updated: 2024/11/18 19:54:54 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*to_int(int n)
{
	int		i;
	char	*s;
	int		negative;

	negative = 0;
	i = num_length(n);
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	s = malloc(i + 1);
	if (!s)
		return (0);
	if (negative == 1)
		s[0] = '-';
	s[i] = '\0';
	while (n > 0)
	{
		s[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (to_int(n));
}
/*
#include <string.h>
#include <stdio.h>
int main (void)
{
	printf("%s", ft_itoa(0));
}
*/	
