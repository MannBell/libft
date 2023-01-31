/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:05:06 by abelayad          #+#    #+#             */
/*   Updated: 2022/10/23 00:34:14 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ++count)
			while (s[i] && s[i] != c)
				i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	**ft_allocater(char const *s, char c, char **strs)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		if (s[i] != c)
		{
			while (s[i] && s[i] != c && ++count)
				i++;
			strs[j] = ft_calloc(count + 1, sizeof(char));
			if (!strs[j])
				return (NULL);
			j++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (strs);
}

static char	**ft_filler(char const *s, char c, char **strs)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] && strs[j])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] && s[i] != c)
				strs[j][k++] = s[i++];
			j++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t		count;
	char		**strs;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	strs = ft_calloc(count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	if (!count)
		return (strs);
	return (ft_filler(s, c, ft_allocater(s, c, strs)));
}
