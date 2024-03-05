/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:02:12 by gperfeit          #+#    #+#             */
/*   Updated: 2022/11/13 18:02:29 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		sign;
	long	ret;
	int		alreadysign;

	ret = 0;
	sign = 1;
	alreadysign = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (alreadysign == 1)
			return (0);
		alreadysign = 1;
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + *s - '0';
		s++;
	}
	return (sign * (int)ret);
}
