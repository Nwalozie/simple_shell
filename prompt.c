#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * my_putint - Prints an integer to stdout
 * @value: The integer value to print
 */

void my_putint(int value)
{
	if (value < 0)
	{
		_putchar('-');
		value = -value;
	}
	if (value >= 10)
		my_putint(value / 10);
	_putchar('0' + value % 10);
}

/**
 * my_putdouble - Prints a double value to stdout
 * @value: The double value to print
 */

void my_putdouble(double value)
{
	int integralPart;
	int fractionalPart;

	integralPart = (int)value;
	my_putint(integralPart);
	_putchar('.');
	fractionalPart = (int) ((value - integralPart) * 1000000);
	if (fractionalPart < 0)
		fractionalPart = -fractionalPart;
	my_putint(fractionalPart);
}

/**
 * print_f - Prints formatted output to stdout
 * @format: The format string
 * @...: Additional arguments based on the format string
 */

void print_f(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				_putchar('%');
			else if (*format == 'd')
			{
				int value = va_arg(args, int);

				my_putint(value);
			}
			else if (*format == 'f')
			{
				double value = va_arg(args, double);

				my_putdouble(value);
			}
			else if (*format == 's')
			{
				char *value = va_arg(args, char*);

				my_puts(value);
			}
		}
		else
			_putchar(*format);
		format++;
	}

	va_end(args);
}

/**
 * child_process - Create a child process and execute a command
 * @str: String to be freed
 * @argv: Arguments for the command
 * @env: Environment variables
 * @av: Command name
 */

void child_process(char *str, char **argv, char **env, char **av)
{
	int stat;
	char *act_command;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		free(str), exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		act_command = get_location(argv[0]);
		if (execve(act_command, argv, env) == -1)
			print_f("%s No such file or directory\n", av[0]);
		exit(0);
	} else
		wait(&stat);
}

/**
 * prompt - Reads user input and executes commands
 * @av: Array of program arguments
 * @env: Array of environment variables
 */

void prompt(char **av, char **env)
{
	char *str = NULL, *argv[MAX_COMMAND];
	int i, j;
	size_t x = 0;
	ssize_t num_char;

	signal(SIGINT, sig_handle);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "cisfun$ ", 8);
		num_char = getline(&str, &x, stdin);
		if (num_char == -1)
		{
			free(str), exit(EXIT_FAILURE);
		}
		if (str_cmp(str, "\n") != 0)
		{
			for (i = 0; str[i]; i++)
			{
				if (str[i] == '\n')
					str[i] = 0;
			}
			j = 0;
			argv[j] = strtok(str, " ");
			while (argv[j] != NULL)
				argv[++j] = strtok(NULL, " ");
			if (str_cmp(argv[0], "exit") == 0)
			{
				free(str), exit(EXIT_SUCCESS);
				break;
			}
			argv[++j] = strtok(NULL, " ");
			child_process(str, argv, env, av);
		}
	}
}
