/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:22:25 by kationg           #+#    #+#             */
/*   Updated: 2025/03/12 10:49:32 by kaijing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(const char c);
int		ft_putstr(const char *s);
int		ft_putptr(void *ptr);
void	print_hex(unsigned long addr);
int		find_hex(unsigned long addr, int flag);
int		ft_finddec(int n);
int		ft_putdec(int n);
int		find_unsigned(unsigned int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned int n, int caseup);

#endif
