#include "cube3d.h"

int	count_chars (char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

void	*freenull(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	*freenulldouble(void **ptr)
{
	unsigned int	i;

	if (ptr)
	{
		i = 0;
		while (ptr[i] != NULL)
		{
			ptr[i] = freenull(ptr[i]);
			i++;
		}
		free(ptr);
	}
	return (NULL);
}

void	fillarray(int *ptr, int size, int filler)
{
	while (size > 0)
	{
		ptr[--size] = filler;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && *s2)
		{
			if (*s1 != *s2 || *s1 == '\0')
				return ((unsigned char)(*s1) - (unsigned char)(*s2));
			s1++;
			s2++;
		}
		return (0);
	}
	return (-1001);
}
