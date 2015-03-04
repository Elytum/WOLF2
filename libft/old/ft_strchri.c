#include "libft.h"

int			ft_strchri(const char *s, int c)
{
	char		*s2;
	int			i;

	i = 0;
	s2 = (char *)s;
	while (*s2)
	{
		if (*s2 == (char)c)
			return (i);
		s2++;
		i++;
	}
	if ((char)c == 0)
		return (i);
	else
		return (-1);
}
