/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clempaol <clempaol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:14:43 by clempaol          #+#    #+#             */
/*   Updated: 2025/12/05 09:33:32 by clempaol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthex(unsigned int nb, int upper);
int	ft_putptr(unsigned long ptr);
int	ft_printf(const char *format, ...);

#endif
