/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 00:40:53 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/11 10:58:21 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "get_next_line.h"
#define BUFFER_SIZE  30

int check_line(char *s)
{
    int i;

    if (!s)
        return (-1);
    i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

void    ft_parse(char **leftover, char *buf, int fd, int *ret)
{
    //printf("===FT_PARSE===\n\n");
    while (check_line(*leftover) == -1 && (*ret = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[*ret] = '\0';
        //printf("buf1: %s\n", buf);
        //printf("leftover1: %s\n", *leftover);
        *leftover = ft_strjoin(*leftover, buf);
        //printf ("leftover: %s\n", *leftover);
        //printf("check line : %d\n", check_line(*leftover));
        //printf("ret: %d\n", *ret);
    }
}

int get_next_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
    static char *leftover = NULL;
    char *temp;
    int ret;

    if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
        return (-1);
    ft_parse(&leftover, buf, fd, &ret);
    //printf("===GET_NEXT_LINE===\n\n");
    //printf("ret: %d\n", ret);
    //printf("check_line: %d\n", check_line(leftover));
    if (check_line(leftover) > -1)
    {
        //printf ("leftover: %s\n", leftover);
        *line = ft_substr(leftover, 0, check_line(leftover));
        //printf("*line: %s\n", *line);
        temp = ft_substr(leftover, check_line(leftover) + 1, ft_strlen(leftover));
        ft_free(leftover);
        leftover = ft_substr(temp, 0, ft_strlen(temp)); 
        ft_free(temp);
        return (1);
    }
    else
    {
        *line = ft_substr(leftover, 0, ft_strlen(leftover));
        ft_free(leftover);
    }
    return (0);
}

int main()
{
    int fd;
    char *line;

    fd = open("monologue_cleopatre.txt", O_RDONLY);
    if (fd == -1)
    {
        printf ("error open");
        return (1);
    }
    //printf("yo");
    while (get_next_line(fd, &line) > 0)
    {    
        printf("%s\n", line);
        ft_free(line);
    }
    printf("%s\n", line);
    ft_free(line);
    if (close(fd) == -1)
    {
        printf("error close");
        return (1);
    }

    return 0;
}