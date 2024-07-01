#include "main.h"

/**
 * print_rev - a function that prints a string,
 * in reverse, followed by a new line.
 * @s : input string
 */

void print_rev(char *s)
{
	int i, k, len;

	len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	i = len;

	for (k = i - 1; k >= 0; k--)
	{
		_putchar(s[k]);
	}

	_putchar('\n');
}

