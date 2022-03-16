/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:18:48 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/09 14:27:17 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_print_arg(const char *str, va_list ap, size_t i)
{
	if (str[i] == 'c')
		return (ft_putchar_len((char)va_arg(ap, int)));
	if (str[i] == 's')
		return (ft_putstr_len(va_arg(ap, char *)));
	if (str[i] == 'p')
		return (ft_pointer(va_arg(ap, unsigned long long)));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_len(va_arg(ap, int)));
	if (str[i] == 'u')
		return (ft_putnbru_len(va_arg(ap, unsigned int)));
	if (str[i] == 'x')
		return (ft_putnbrhex_low(va_arg(ap, unsigned int )));
	if (str[i] == 'X')
		return (ft_putnbrhex_high(va_arg(ap, unsigned int )));
	if (str[i] == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	counter;
	size_t	i;
	va_list	ap;

	counter = 0;
	i = 0;
	va_start(ap, str);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			counter += ft_print_arg(str, ap, ++i);
		}
		else
		{
			write (1, &str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(ap);
	return (counter);
}
