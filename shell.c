#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @env: Array of environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		prompt(argv, env);

	return (0);
}
