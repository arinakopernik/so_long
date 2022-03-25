/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:11:57 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 14:12:09 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_define_param(const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*str == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*str == 'p')
		count += ft_putptr(va_arg(args, unsigned long int));
	else if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*str == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	else if (*str == 'x')
		count += ft_low_hexa(va_arg(args, unsigned int), count);
	else if (*str == 'X')
		count += ft_up_hexa(va_arg(args, unsigned int), count);
	else if (*str == '%')
	{
		write(1, str, 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (0);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			str++;
			count++;
		}
		if (*str == '%')
		{
			count += ft_define_param(++str, args);
			str++;
			continue ;
		}
	}
	va_end(args);
	return (count);
}
