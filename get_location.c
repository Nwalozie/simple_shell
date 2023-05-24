#include "shell.h"

/**
 * get_env - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *get_env(const char *name)
{
        int i;

        size_t name_length = strlen(name);

        for (i = 0; environ[i] != NULL; i++)
        {
                if (strn_cmp(name, environ[i], name_length) == 0
                                && environ[i][name_length] == '=')
                        return (environ[i] + name_length + 1);
        }

        return (NULL);
}

/**
 * get_location - Retrieves the location of a command in the PATH.
 * @command: The command whose location needs to be determined.
 *
 * Return: The full path to the command if found, NULL otherwise.
 */

char *get_location(char *command)
{
        char *path, *path_cp, *path_token, *file_path;
        int command_length, directory_length;
        struct stat buffer;

        path = get_env("PATH");
        if (path)
        {
                command_length = str_len(command);
                path_cp = strdup(path);
                path_token = strtok(path_cp, ":");
                while (path_token != NULL)
                {
                        directory_length = str_len(path_token);

                        file_path = malloc(command_length + directory_length + 2);

                        str_cpy(file_path, path_token);
                        str_cat(file_path, "/");
                        str_cat(file_path, command);
                        str_cat(file_path, "\0");
                        if (stat(file_path, &buffer) == 0)
                        {
                                free(path_cp);
                                return (file_path);
                        }
                        else
                        {
                                free(file_path);
                                path_token = strtok(NULL, ":");
                        }
                }

                free(path_cp);
                if (stat(command, &buffer) == 0)
                {
                        return (command);
                }
                return (NULL);
        }
        return (NULL);
}
