/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:51:06 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/28 11:43:23 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char *s);
size_t	ft_strlen(const char *s);
int		check_line(char *s, char c);
int	    ft_parse(char **leftover, char *buf, int fd);
int		get_next_line(int fd, char **line);
int		split_size(char const *s, char c);
char	*alloc_array(char const *s, char c);
char	**ft_split(char const *s, char c);

#endif
