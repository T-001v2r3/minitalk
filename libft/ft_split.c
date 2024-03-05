/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:54:50 by gperfeit          #+#    #+#             */
/*   Updated: 2024/03/05 15:01:12 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_num_strings(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
	}
	return (j);
}

static int	less_lines(char const *s, char c, char **ret, int k)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			ret[k] = ft_substr(s, j, i - j);
			if (!ret[k])
			{
				while (k >= 0)
					free(ret[k--]);
				free(ret);
				return (-1);
			}
			k++;
		}
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	j;
	int		k;

	k = 0;
	if (!s)
		return (NULL);
	j = check_num_strings(s, c);
	ret = (char **)malloc(sizeof(char *) * (j + 1));
	if (!ret)
		return (NULL);
	k = less_lines(s, c, ret, 0);
	if (k == -1)
		return (NULL);
	ret[k] = NULL;
	return (ret);
}
