#include "shell.h"

/**
 *str_len - return length to a string
 *@y: The character to count
 * Return: return an integer "x"
 */

int str_len(char *y)
{
	int x = 0;

	while (y[x] != '\0')
		x++;
	return (x);
}
