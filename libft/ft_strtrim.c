/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:53:04 by gperfeit          #+#    #+#             */
/*   Updated: 2022/11/13 18:04:48 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[i + j])
		j++;
	while (j && ft_strchr(set, s1[i + j - 1]))
		j--;
	ret = (char *)malloc(sizeof(char) * (j + 1));
	if (!ret)
		return (NULL);
	while (k < j)
		ret[k++] = s1[i++];
	ret[k] = '\0';
	return (ret);
}
