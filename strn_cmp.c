#include "shell.h"

/**
 * strn_cmp - Compare two strings up to a specified length
 * @str1: The first string to compare
 * @str2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: 0 if the strings are equal, negative value if str1 < str2,
 *         positive value if str1 > str2
 */

int strn_cmp(const char *str1, const char *str2, size_t n)
{
        size_t i;

        for (i = 0; i < n; i++)
        {
                if (str1[i] != str2[i])
                        return (str1[i] - str2[i]);
                else if (str1[i] == '\0')
                        return (0);
        }
        return (0);
}
