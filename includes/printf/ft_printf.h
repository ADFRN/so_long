/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:43:15 by afournie          #+#    #+#             */
/*   Updated: 2025/12/01 10:05:49 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FORMAT_CHAR 'c'
# define FORMAT_STR 's'
# define FORMAT_POINT 'p'
# define FORMAT_DECIMAL 'd'
# define FORMAT_INT 'i'
# define FORMAT_UDESC 'u'
# define FORMAT_HEXALOW 'x'
# define FORMAT_HEXAUPP 'X'
# define FORMAT_PERCENT '%'

void	ft_print(const char s, va_list *arg, int *count);
int		ft_printf(const char *s, ...);
int		ft_is_format(const char s);
int		ft_putnbr_hexa_low(unsigned long n);
int		ft_putnbr_hexa_up(unsigned int n);
int		ft_putnbr_udesc(unsigned int n);
int		ft_print_ptr(void *adress);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);

#endif
