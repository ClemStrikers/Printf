/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clempaol <clempaol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:46:15 by clempaol          #+#    #+#             */
/*   Updated: 2025/12/01 16:46:15 by clempaol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += print_hex(nb / 16, base);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_puthex(unsigned int nb, int upper)
{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (print_hex(nb, base));
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += ft_putstr("0x");
	count += print_hex(ptr, "0123456789abcdef");
	return (count);
}

