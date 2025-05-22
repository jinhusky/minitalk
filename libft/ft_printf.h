/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:22:25 by kationg           #+#    #+#             */
/*   Updated: 2025/05/23 01:14:44 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(const char c);
int		ft_putstr(const char *s);
int		ft_putptr(void *ptr);
int		ft_putdec(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned int n, int caseup);

#endif
