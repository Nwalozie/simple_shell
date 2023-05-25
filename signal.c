#include "shell.h"

/**
 * sig_handle - This is a function to check ctrl C
 * @sig: input
 * Return: nothing
 */

void sig_handle(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\ncisfun~$ ", 10);

}
