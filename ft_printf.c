/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezongo <mpezongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:23 by mpezongo          #+#    #+#             */
/*   Updated: 2022/10/25 14:38:53 by mpezongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_check_printf(char c, int *len, va_list ap)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (c == 'c')
		*len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
	{
		*len += ft_putstr("0x");
		ft_put_hex((unsigned long long)va_arg(ap, char *), c, len);
	}
	else if (c == 'u')
		ft_put_unsigned_nbr(va_arg(ap, unsigned int), len);
	else if (c == 'x')
		ft_put_hex((unsigned int)va_arg(ap, char *), c, len);
	else if (c == 'X')
		ft_put_hex((unsigned int)va_arg(ap, char *), c, len);
	else if (c == '%')
		*len += ft_putchar('%');
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			ft_check_printf(*(++s), &len, ap);
		else
		{
			len++;
			write(1, s, 1);
		}
		s++;
	}
	va_end (ap);
	return (len);
}
