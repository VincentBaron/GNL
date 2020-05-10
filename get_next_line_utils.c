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

void    ft_free(char *s)
{
    free(s);
    s = NULL;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		size;
	int		i;

    if (!s1)
        s1 = "";
   // printf("s1len: %d\n", (int)ft_strlen(s1));
    size = ft_strlen(s1) + ft_strlen(s2);
    //printf ("size: %d\n", size);
	if (!(join = malloc(sizeof(char) * (size + 1))))
		return (NULL);
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
    //printf ("join: %s\n", join);
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

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