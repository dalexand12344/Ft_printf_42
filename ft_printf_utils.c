/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <dalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:05:27 by dalexand          #+#    #+#             */
/*   Updated: 2023/11/16 16:56:16 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ptr_len)
{
	*ptr_len += write(1, &c, 1);
}

void	print_nmb(int nb, int *ptr_len)
{
	if (nb == -2147483648)
		*ptr_len += write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-', ptr_len);
		nb *= -1;
	}
	if (nb >= 10)
	{
		print_nmb(nb / 10, ptr_len);
		print_nmb(nb % 10, ptr_len);
	}
	if (nb < 10 && nb >= 0)
		ft_putchar(nb + '0', ptr_len);
}

void	print_address(unsigned long int nb, int *ptr_len)
{
	if (nb >= 16)
	{
		print_address(nb / 16, ptr_len);
		print_address(nb % 16, ptr_len);
	}
	if (nb < 16)
		ft_putchar("0123456789abcdef"[nb], ptr_len);
}

void	print_unsigned(unsigned int nb, int *ptr_len)
{
	if (nb >= 10)
	{
		print_unsigned(nb / 10, ptr_len);
		print_unsigned(nb % 10, ptr_len);
	}
	if (nb < 10)
		ft_putchar(nb + '0', ptr_len);
}

void	print_hexadecimal(unsigned int nb, char c, int *ptr_len)
{
	if (nb >= 16)
	{
		print_hexadecimal(nb / 16, c, ptr_len);
		print_hexadecimal(nb % 16, c, ptr_len);
	}
	if (nb < 16)
	{
		if (c == 'x')
			ft_putchar("0123456789abcdef"[nb], ptr_len);
		else if (c == 'X')
			ft_putchar("0123456789ABCDEF"[nb], ptr_len);
	}
}
