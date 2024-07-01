#include "main.h"

/**
 * puts_half - function that prints half of a string
 * followed by a new line.
 * @str : input string
 */

void puts_half(char *str)
{
	int i, len;
	char *s = str;

	len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	if (len % 2 == 0)
	{
		i = len / 2;
	}
	else
	{
		i = (len + 1) / 2;
	}
	for ( ; i < len; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}

