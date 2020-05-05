#include "get_next_line.h"

size_t  ft_strlen(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
	 yo
}

void    ft_free(char *str)
{
    str = NULL;
    free(str);
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
		return (0);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		size;
	int		i;

	
	if (!s1)
		s1 = ft_substr("", 0, 0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = malloc(sizeof(char) * size)))
		return (0);
	i = 0;
	while (*s1 && i < size)
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 && i < size)
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = '\0';
	ft_free(s1);
	return (join);
}