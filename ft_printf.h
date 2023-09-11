/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezongo <mpezongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:11:13 by mpezongo          #+#    #+#             */
/*   Updated: 2022/10/24 21:13:30 by mpezongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr(int nb, int *len);
void	ft_put_hex(unsigned long long nb, char x, int *len);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_put_unsigned_nbr(unsigned int nb, int *len);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);

#endif
