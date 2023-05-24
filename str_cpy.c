#include "shell.h"

/**
 * str_cpy - copies the string pointed to by src
 * @dest: copy the string
 * @src: the string to copy
 * Return: value to pointer dest
 */

char *str_cpy(char *dest, char *src)
{
        int i = 0;

        while (src[i])
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';

        return (dest);
}
