#include "main.h"

/**
 * _strncpy - Function to copy at most n bytes of src to dest
 * @dest : destination
 * @src : source
 * @n : byte size
 *
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (n > 0 && *src != '\0')
	{
		*ptr++ = *src++;
		n--;
	}

	while (n > 0)
	{
		*ptr++ = '\0';
		n--;
	}


	return (dest);
}
