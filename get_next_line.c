/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 00:40:53 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/28 12:01:58 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

int		check_line(char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_parse(char **leftover, char *buf, int fd)
{
	int ret;

	while (check_line(*leftover, '\n') == -1
	&& (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*leftover = ft_strjoin(*leftover, buf);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*leftover = NULL;
	static int ret;
	static char **lines_list;
	static int check = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (check == 0)
	{
		if(!(lines_list = (char **)malloc(sizeof(char *))))
			return (-1);
		*lines_list = NULL;
		check = 1;
	}
	if (*lines_list == NULL)
	{
		ret = ft_parse(&leftover, buf, fd);
		lines_list = ft_split(leftover, '\n');
		ft_free(leftover);
	}
	*line = ft_substr(lines_list[0], 0, ft_strlen(lines_list[0]));
	ft_free(lines_list[0]);
	lines_list++;
	if (ret == 0)
		return 0;
	return (1);
}