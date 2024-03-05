/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:04:00 by gperfeit          #+#    #+#             */
/*   Updated: 2024/03/05 14:00:59 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		ret = ft_strdup("");
		return (ret);
	}
	if (s_len - start < len)
		len = s_len - start;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}
