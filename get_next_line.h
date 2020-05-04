#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
void    ft_free(char *str);
size_t  ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
