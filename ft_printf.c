/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clempaol <clempaol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:20:33 by clempaol          #+#    #+#             */
/*   Updated: 2025/12/03 14:33:43 by clempaol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	dispatch(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	else if (c == 's')
		ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
	{
		ft_putstr("0x");
		ft_putptr(va_arg(ap, unsigned long));
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		ft_puthex(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		ft_puthex(va_arg(ap, unsigned int), 1);
	else if (c == '%')
		ft_putchar('%');
	else
		ft_putchar(c);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			dispatch(format[i], ap);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

// int	main(void)
// {
// 	char *c = "shajfs";
// 	printf("\n%d\n", printf("%s", c));
// 	return (0);
// }