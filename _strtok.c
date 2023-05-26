#include "shell.h"

/**
 * _strtok - Tokenizes a string based on delimiters
 * @str: The string to be tokenized
 * @d: The delimiters to use for tokenization
 *
 * Return: A pointer to the next token in the string
 */

char *_strtok(char *str, const char *d)
{
	unsigned int k;
	static char *tok, *n_tok;

	if (str != NULL)
		n_tok = str;
	tok = n_tok;
	if (tok == NULL)
		return (NULL);

			for (k = 0; tok[k] != '\0'; k++)
			{
				if (is_delim(tok[k], d) == 0)
					break;
			}
	if (n_tok[k] == '\0' || n_tok[k] == '#')
	{
		n_tok = NULL;
		return (NULL);
	}
	tok = n_tok + k;
	n_tok = tok;
	for (k = 0; n_tok[k] != '\0'; k++)
	{
		if (is_delim(n_tok[k], d) == 1)
			break;
	}
	if (n_tok[k] == '\0')
		n_tok = NULL;
	else
	{
		n_tok[k] == '\0';
		n_tok[k] = n_tok + k + 1;
		if (*n_tok == '\0')
			n_tok = NULL;
	}
	return (tok);
}
