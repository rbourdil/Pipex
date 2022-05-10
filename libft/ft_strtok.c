#include "pipex.h"

inline static int	isdelim(char c, const char *delim)
{
	while (*delim != '\0')
		if (*delim++ == c)
			return (1);
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*p;
	char		*tok;

	if (str != NULL)
	{
		while (isdelim(*str, delim))
			str++;
		p = str;
	}
	if (*p == '\0')
		return (NULL);
	tok = p;
	while (*p != '\0' && !isdelim(*p, delim))
		p++;
	while (*p != '\0' && isdelim(*p, delim))
		*p++ = '\0';
	return (tok);
}
