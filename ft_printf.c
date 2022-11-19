/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:34:54 by nmaazouz          #+#    #+#             */
/*   Updated: 2022/11/19 18:12:44 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(char c, int *sum, va_list ls_arg)
{
	if (c == 'c')
		*sum += ft_putchar(va_arg(ls_arg, int));
	else if (c == 's')
		*sum += ft_putstr(va_arg(ls_arg, char *));
	else if (c == 'd' || c == 'i')
		*sum += ft_putnbr(va_arg(ls_arg, int));
	else if (c == 'u')
		*sum += ft_putunbr(va_arg(ls_arg, unsigned int));
	else if (c == 'x' || c == 'X')
		*sum += ft_puthexa(va_arg(ls_arg, unsigned int), c);
	else if (c == 'p')
	{
		*sum += write(1, "0x", 2);
		*sum += ft_puthexa(va_arg(ls_arg, unsigned long long), 'x');
	}
	else if (c == '%')
		*sum += ft_putchar('%');
	else if (c == '\0')
		return ;
	else
		*sum += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	va_list	ls_arg;	

	i = 0;
	result = 0;
	va_start(ls_arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (result);
			ft_check(format[i + 1], &result, ls_arg);
			i++;
		}
		else
			result += ft_putchar(format[i]);
		i++;
	}
	va_end(ls_arg);
	return (result);
}
