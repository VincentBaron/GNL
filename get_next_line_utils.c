/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:51:19 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/27 21:00:10 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*join;
	unsigned int	size;
	unsigned int	i;
	unsigned int	f;

	if (!s1)
		s1 = ft_substr("", 0, 0);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = malloc(sizeof(char) * (size + 1))))
	{
		ft_free(s1);
		return (NULL);
	}
	i = 0;
	f = 0;
	while (s1[i])
		join[f++] = s1[i++];
	i = 0;
	while (s2[i])
		join[f++] = s2[i++];
	join[f] = '\0';
	ft_free(s1);
	return (join);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		s = "";
	if (start > ft_strlen(s))
		len = 0;
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

int		split_size(char const *s, char c)
{
	int	element;

	element = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			element++;
			while (*s != c && *s)
				s++;
		}
	}
	return (element + 1);
}

char	*alloc_array(char const *s, char c)
{
	int		i;
	char	*array;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (split_size(s, c)))))
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			split[i] = alloc_array(s, c);
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
