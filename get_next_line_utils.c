#include "get_next_line.h"

int  ft_strlen(char *s)
{
    int i;
    
    i = 0;
	 if (!s)
	 	return(0);
    while (s[i])
    {
        i++;
    }
    return (i);
}

char    *ft_free(char *str)
{
   free(str);
	str = NULL;
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	char			*sub;
	int	i;

	if (!s)
		return (NULL);
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

	if (!s1 || !s2)
		return (NULL);
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
	return (join);
}
