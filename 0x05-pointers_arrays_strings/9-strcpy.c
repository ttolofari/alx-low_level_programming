#include "main.h"

/**
 * *_strcpy - a funnction that copies a string from
 * src to dest
 * @src : source location
 * @dest : destination location
 * Return : the destination
 */

char *_strcpy(char *dest, char *src)
{
	char *origin = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (origin);
}
