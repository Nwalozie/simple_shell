#include "shell.h"

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A pointer to the resulting string representation of the integer.
 */

char *_itoa(int n)
{
        char *ptr;
        unsigned int c;
        int count;

        count = count_num(n);

        ptr = malloc(sizeof(char) * (count + 1));
        if (!ptr)
                return (NULL);

        ptr[count] = '\0';

        if (n < 0)
        {
                c = n * -1;
                ptr[0] = '-';
        }
        else
                c = n;

        count--;
        do {
                ptr[count] = (c % 10) + '0';
                c /= 10;
                count--;
        } while (c > 0);

        return (ptr);
}
