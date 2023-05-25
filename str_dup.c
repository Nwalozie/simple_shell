#include "shell.h"

/**
 * str_dup - returns a pointer to a newly allocated space in memory.
 * @str: The string to copy.
 * Return: The string copy.
 */

char *str_dup(char *str)
{
	char *dest;
	int i = 0;
	int b;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[i])
	{
		i++;
	}
	i++;

	dest = malloc(sizeof(char) * i);

	if (dest == 0)
	{
		return (NULL);
	}

	for (b = 0; b <= i; b++)
	{
		dest[b] = str[b];
	}
	return (dest);
}
