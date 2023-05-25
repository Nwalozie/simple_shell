#include "shell.h"

/**
 * str_cat - Concatenate two strings
 * @dest: array 1
 * @src: array 2
 * Return: dest
 */
char *str_cat(char *dest, char *src)
{
	int x = 0, y;

	while (dest[x] != '\0')
		x++;

	for (y = 0; src[y] != '\0'; y++, x++)
	{
		dest[x] = src[y];
	}

	return (dest);
}
