/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <dalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:24:19 by dalexand          #+#    #+#             */
/*   Updated: 2023/11/16 16:56:15 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *ptr_len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*ptr_len += write(1, str++, 1);
}

void	ft_format(char c, va_list *args, int *ptr_len)
{
	unsigned long int	p;

	if (c == 'c')
		ft_putchar(va_arg(*args, int), ptr_len);
	if (c == '%')
		*ptr_len += write(1, "%", 1);
	if (c == 'd' || c == 'i')
		print_nmb(va_arg(*args, int), ptr_len);
	if (c == 'u')
		print_unsigned(va_arg(*args, unsigned int), ptr_len);
	if (c == 'x' || c == 'X')
		print_hexadecimal(va_arg(*args, unsigned int), c, ptr_len);
	if (c == 'p')
	{
		p = va_arg(*args, unsigned long int);
		if (!p)
			ft_putstr((char *)PTR_NULL, ptr_len);
		else
		{
			*ptr_len += write(1, "0x", 2);
			print_address(p, ptr_len);
		}
	}
	if (c == 's')
		ft_putstr(va_arg(*args, char *), ptr_len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			len += write(1, format, 1);
		if (*format == '%')
			ft_format(*++format, &args, &len);
		format++;
	}
	va_end(args);
	return (len);
}
