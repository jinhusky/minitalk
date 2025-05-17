/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:07:52 by kationg           #+#    #+#             */
/*   Updated: 2025/05/17 21:10:23 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *str, ...);
int		ft_putptr(void *ptr);
void	print_hex(unsigned long addr);
int		find_hex(unsigned long addr, int flag);
int		ft_finddec(int n);
int		ft_putdec(int n);
int		find_unsigned(unsigned int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned int n, int caseup);

#endif
