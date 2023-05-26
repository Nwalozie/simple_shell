#include "shell.h"

/**
 * not_found - Displays an error message for a command not found.
 * @input: The input command.
 * @line: The line number where the error occurred.
 * @cmd: An array of command arguments.
 */

void not_found(char *input, int line, char **cmd)
{
        char *num;

        DISPLAY(cmd[0]);
        DISPLAY(": ");
        num = _itoa(line);
        DISPLAY(num);
        free(num);
        DISPLAY(": ");
        DISPLAY(input);
        DISPLAY(": not found\n");
}
