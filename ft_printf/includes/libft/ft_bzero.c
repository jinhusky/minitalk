/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:30:11 by kationg           #+#    #+#             */
/*   Updated: 2024/11/23 18:11:44 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//same as memset except instead of constent 
//character c, fill in with 0 for n number of bytes
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
