/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezongo <mpezongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:10:41 by mpezongo          #+#    #+#             */
/*   Updated: 2022/10/24 20:01:17 by mpezongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		write(1, &"-2", 2);
		ft_putnbr(147483648, len);
		(*len) += 2;
	}
	else if (nb < 0)
	{
		write(1, &"-", 1);
		ft_putnbr(-nb, len);
		(*len)++;
	}
	else
	{
		if ((nb <= 9) && (nb >= 0))
		{
			ft_putchar(nb + '0');
			(*len)++;
		}
		else
		{
			ft_putnbr(nb / 10, len);
			ft_putnbr(nb % 10, len);
		}
	}
}

void	ft_put_hex(unsigned long long nb, char x, int *len)
{
	char	*uphex;
	char	*lowhex;

	lowhex = "0123456789abcdef";
	uphex = "0123456789ABCDEF";
	if (nb < 0)
	{
		ft_putchar('-');
		ft_put_hex(-nb, x, len);
	}
	if (nb < 16)
	{
		if (x == 'x' || x == 'p')
			ft_putchar(lowhex[nb]);
		else
			ft_putchar(uphex[nb]);
		(*len)++;
	}
	else
	{
		ft_put_hex(nb / 16, x, len);
		ft_put_hex(nb % 16, x, len);
	}
}

void	ft_put_unsigned_nbr(unsigned int nb, int *len)
{
	if ((nb <= 9) && (nb >= 0))
	{
		ft_putchar(nb + '0');
		(*len)++;
	}
	else
	{
		ft_put_unsigned_nbr(nb / 10, len);
		ft_put_unsigned_nbr(nb % 10, len);
	}
}
