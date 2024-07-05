#include "main.h"

/**
 * string_toupper - a function that changes all lowercase letters of a string to uppercase.
 * @str : input string.
 *
 */

char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = *ptr - 'a' + 'A';
		}
		
		ptr++;
	}

	return (str);
}


