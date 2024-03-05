/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:52:17 by gperfeit          #+#    #+#             */
/*   Updated: 2022/11/13 17:56:14 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		ret[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
