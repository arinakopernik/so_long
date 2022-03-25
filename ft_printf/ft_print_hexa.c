/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:13:06 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 14:13:08 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_low_hexa(unsigned long long int n, int count)
{
	count = 0;
	if (n >= 16)
		count += ft_low_hexa(n / 16, count);
	n %= 16;
	if (n > 9 && n <= 16)
	{
		if (n == 10)
			ft_putchar('a');
		if (n == 11)
			ft_putchar('b');
		if (n == 12)
			ft_putchar('c');
		if (n == 13)
			ft_putchar('d');
		if (n == 14)
			ft_putchar('e');
		if (n == 15)
			ft_putchar('f');
	}
	if (n <= 9)
		ft_putchar(n + '0');
	count++;
	return (count);
}

int	ft_up_hexa(unsigned long long int n, int count)
{
	count = 0;
	if (n >= 16)
		count += ft_up_hexa(n / 16, count);
	n %= 16;
	if (n > 9 && n <= 16)
	{
		if (n == 10)
			ft_putchar('A');
		if (n == 11)
			ft_putchar('B');
		if (n == 12)
			ft_putchar('C');
		if (n == 13)
			ft_putchar('D');
		if (n == 14)
			ft_putchar('E');
		if (n == 15)
			ft_putchar('F');
	}
	if (n <= 9)
		ft_putchar(n + '0');
	count++;
	return (count);
}
