/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:13:52 by gperfeit          #+#    #+#             */
/*   Updated: 2022/11/13 18:22:13 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!big)
		return (NULL);
	if (!little || little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		y = 0;
		while (big[i] && big[i + y] == little[y] && (i + y) < len)
		{
			y++;
			if (little[y] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
