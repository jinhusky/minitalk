/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:55:27 by kationg           #+#    #+#             */
/*   Updated: 2024/11/25 16:34:49 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static size_t	substr_len(char const *s, char c)
{
	int		flag;
	size_t	len;

	len = 0;
	while (*s)
	{
		flag = 0;
		while (*s == c && *s)
		{
			s++;
		}
		while (*s != c && *s)
		{
			if (flag == 0)
			{
				flag = 1;
				len++;
			}
			s++;
		}
	}
	return (len);
}

static void	free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i++]);
	}
	free(list);
}

static int	allo_substr(char **split, const char *s, size_t len, size_t *i)
{
	split[*i] = malloc(len + 1);
	if (!split[*i])
	{
		free_list(split);
		return (0);
	}
	ft_strlcpy(split[*i], s, len + 1);
	(*i)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	split = malloc((substr_len(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len && !allo_substr(split, s - len, len, &i))
			return (NULL);
	}
	split[i] = 0;
	return (split);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Test string and delimiter
    char **list = ft_split("Hi my name is Vicky !", ' ');

    // Check if the split was successful
    if (list == NULL)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }

    // Print each substring
    for (int i = 0; list[i] != NULL; i++)
    {
        printf("list[%d] = %s\n", i, list[i]);
    }

    // Free the memory allocated by ft_split
    free_list(list);

    return (0);
}
*/
