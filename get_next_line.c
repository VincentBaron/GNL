/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 00:40:53 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/05 15:40:43 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "get_next_line.h"
#define BUFFER_SIZE  30

int check_line(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == '\n')
            printf("i1: %d\n", i);
            return (i);
        i++;
    }
    return (-1);
}

void    read_file(int fd, char **leftover, char *buf, int *res)
{   
    while(check_line(*leftover) == -1 && (*res = read(fd, buf, BUFFER_SIZE) > 0))
    {
        buf[*res] = '\0';
        *leftover = ft_strjoin(*leftover, buf);
    }
}

int get_next_line(int fd, char **line)
{
    static char *leftover = NULL;
    char *tmp;
    char buf[BUFFER_SIZE + 1];
    int res;

    if (fd < 0 || BUFFER_SIZE < 1 || (res = read(fd, buf, 0)) < 0 || line == NULL)
        return (-1);
    read_file(fd, &leftover, buf, &res);
    if (check_line(leftover) > -1)
    {
        *line = ft_substr(leftover, 0, check_line(leftover));
        tmp = ft_substr(leftover, 0, ft_strlen(leftover));
        leftover = ft_free(leftover);
        leftover = ft_substr(tmp, check_line(tmp) + 1, ft_strlen(tmp));
        tmp = ft_free(tmp);
        return (1);
    }
    else
    {
        *line = ft_substr(leftover, 0, ft_strlen(leftover));
        leftover = ft_free(leftover);
    }
    return (0);
    
}

int main()
{
    int fd;
    char *line;
    int ret;

    fd = open("monologue_cleopatre.txt", O_RDONLY);
    if (fd == -1)
    {
        printf ("error open");
        return (1);
    }
    printf("yo");
    while ((ret = get_next_line(fd, &line)) > 0)
    {    
        printf("%s\n", line);
    }
    if (close(fd) == -1)
    {
        printf("error close");
        return (1);
    }

    return 0;
}