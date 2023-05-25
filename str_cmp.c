#include "shell.h"

/**
 * str_cmp - compares two strings
 * @x: first string
 * @y: second string
 * Return: the diference between x and y
 */

int str_cmp(char *x, char *y)
{
	while ((*x != '\0' && *y != '\0') && *x == *y)
	{
		x++;
		y++;
	}

	if (*x == *y)
	{
		return (0);
	}

	else
	{
		return (*x - *y);
	}
}
