/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clempaol <clempaol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:20:33 by clempaol          #+#    #+#             */
/*   Updated: 2025/12/05 11:32:07 by clempaol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(ap, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += dispatch(format[i], ap);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

// int main(void)
// {
// 	ft_printf("Tout les tests\n");
// 	ft_printf("Char: %c\n", 'A');
// 	ft_printf("String: %s\n", "Hello");
// 	ft_printf("Pointer: %p\n", (void *)0x1234);
// 	ft_printf("Decimal: %d\n", -42);
// 	ft_printf("Unsigned: %u\n", 42);
// 	ft_printf("Hex lower: %x\n", 255);
// 	ft_printf("Hex upper: %X\n", 255);
// 	ft_printf("Percent: %%\n");

// 	printf("\nVrai Printf\n");
// 	printf("Char: %c\n", 'A');
// 	printf("String: %s\n", "Hello");
// 	printf("Pointer: %p\n", (void *)0x1234);
// 	printf("Decimal: %d\n", -42);
// 	printf("Unsigned: %u\n", 42);
// 	printf("Hex lower: %x\n", 255);
// 	printf("Hex upper: %X\n", 255);
// 	printf("Percent: %%\n");

// 	return (0);
// }
