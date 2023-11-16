/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <dalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:48:39 by dalexand          #+#    #+#             */
/*   Updated: 2023/11/16 16:56:13 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# if defined(__APPLE__)
#  define PTR_NULL "0x0"
# elif __linux__
#  define PTR_NULL "(nil)"
# else
#  define PTR_NULL "(nil)"
# endif

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *ptr_len);
void	ft_putstr(char *str, int *ptr_len);
void	print_nmb(int nb, int *ptr_len);
void	print_address(unsigned long int nb, int *ptr_len);
void	ft_format(char c, va_list *args, int *ptr_len);
void	print_hexadecimal(unsigned int nb, char c, int *ptr_len);
void	print_unsigned(unsigned int nb, int *ptr_len);
#endif
