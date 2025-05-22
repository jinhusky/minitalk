/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:23:13 by kationg           #+#    #+#             */
/*   Updated: 2025/05/23 01:16:21 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	find_hex(unsigned long addr, int flag)
{
	size_t	size;

	size = 2;
	if (flag == 1)
		size = 0;
	if (addr == 0)
		return (1);
	while (addr > 0)
	{
		addr /= 16;
		size++;
	}
	return (size);
}

static void	print_hex(unsigned long addr)
{
	const char	*base_16 = "0123456789abcdef";

	if (addr >= 16)
		print_hex(addr / 16);
	ft_putchar(base_16[addr % 16]);
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	print_hex((unsigned long) ptr);
	return (find_hex((unsigned long) ptr, 0));
}

int	ft_puthex(unsigned int n, int caseup)
{
	char	*base_16;

	base_16 = "0123456789abcdef";
	if (caseup == 1)
		base_16 = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthex(n / 16, caseup);
	ft_putchar(base_16[n % 16]);
	return (find_hex(n, 1));
}
