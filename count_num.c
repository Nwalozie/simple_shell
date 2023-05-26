#include "shell.h"

/**
 * count_num - Counts the number of digits in an integer
 * @n: The integer to count digits for
 *
 * Return: The number of digits in the integer
 */

int count_num(int n)
{
        unsigned int c;
        int count = 1;

        if (n < 0)
        {
                count++;
                c = n * -1;
        }
        else
                c = n;
        while (c > 9)
        {
                count++;
                c /= 10;
        }

        return (count);
}
