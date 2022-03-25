/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:12:36 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 14:12:48 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_u(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

static int	ft_print_neg(int n)
{
	int	count;

	count = 0;
	if (n <= -10)
		count += ft_print_neg((n / 10));
	count += ft_putchar(('0' - (n % 10)));
	return (count);
}

static int	ft_printnum(int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_printnum(n / 10);
	count += ft_putchar(((n % 10) + '0'));
	return (count);
}

int	ft_putnbr(int n)
{
	int				count;
	long long int	nbr;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		count += ft_print_neg(n);
	}
	else if (n > 0)
		count += ft_printnum(n);
	else
	{
		write(1, "0", 1);
		count++;
	}
	return (count);
}
