#include "shell.h"

/**
 * my_puts - Prints a string to stdout
 * @str: The string to print
 */

void my_puts(const char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
