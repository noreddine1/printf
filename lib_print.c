/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:48:52 by nmaazouz          #+#    #+#             */
/*   Updated: 2022/11/17 23:45:42 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		sum += ft_putchar(str[i]);
		i++;
	}
	return (sum);
}

int	ft_putnbr(int n)
{
	int			sum;
	long int	nb;

	sum = 0;
	nb = n;
	if (n < 0)
	{
		sum += ft_putchar('-');
		nb *= -1;
	}
	sum += ft_putunbr(nb);
	return (sum);
}

int	ft_putunbr(unsigned int n)
{
	int	sum;

	sum = 0;
	if (n < 10)
		return (ft_putchar(n + '0'));
	else
	{
		sum += ft_putnbr(n / 10);
		sum += ft_putchar(n % 10 + '0');
	}
	return (sum);
}

int	ft_puthexa(unsigned long long n, char c)
{
	int	sum;

	sum = 0;
	if (n < 10)
		return (ft_putchar(n + '0'));
	else if (n < 16 && c == 'x')
		return (ft_putchar(n - 10 + 'a'));
	else if (n < 16 && c == 'X')
		return (ft_putchar(n - 10 + 'A'));
	else
	{
		sum += ft_puthexa(n / 16, c);
		sum += ft_puthexa(n % 16, c);
	}
	return (sum);
}
