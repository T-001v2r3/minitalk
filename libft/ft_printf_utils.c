/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:59:18 by gperfeit          #+#    #+#             */
/*   Updated: 2022/12/01 21:53:08 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

void	ft_put_hex(unsigned int value, int *len, int upper)
{
	if (value >= 16)
	{
		ft_put_hex(value / 16, len, upper);
		ft_put_hex(value % 16, len, upper);
	}
	else
	{
		if (value < 10)
			(*len) += ft_put_char(value + '0');
		else if (upper == 'x')
			(*len) += ft_put_char(value - 10 + 'a');
		else if (upper == 'X')
			(*len) += ft_put_char(value - 10 + 'A');
	}
}

void	ft_put_nbr(unsigned int value, int *len, int unsig)
{
	if (!unsig && ((int)value) < 0)
	{
		write(1, "-", 1);
		(*len)++;
		value *= -1;
	}
	if (value >= 10)
	{
		ft_put_nbr(value / 10, len, unsig);
		ft_put_nbr(value % 10, len, unsig);
	}
	else
		(*len) += ft_put_char(value + '0');
}

void	ft_put_ptr(unsigned long long p, int *len)
{
	if (p >= 16)
	{
		ft_put_ptr(p / 16, len);
		ft_put_ptr(p % 16, len);
	}
	else
	{
		if (p < 10)
			(*len) += ft_put_char(p + '0');
		else
			(*len) += ft_put_char(p - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long p)
{
	int	size;

	if (!p)
		return (ft_put_str("(nil)"));
	size = 0;
	size += write(1, "0x", 2);
	ft_put_ptr(p, &size);
	return (size);
}
