/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:27:42 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/27 20:37:28 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int fd;
    char *line;
    int ret;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        printf ("error open");
        return (1);
    }
    while ((ret = get_next_line(fd, &line)) > 0)
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