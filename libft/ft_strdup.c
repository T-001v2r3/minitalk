/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:21:45 by gperfeit          #+#    #+#             */
/*   Updated: 2022/11/20 22:07:57 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
