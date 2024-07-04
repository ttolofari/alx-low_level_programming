#include "main.h"
/**
 * *_strncat - function to concatenate up to n bytes of src to dest
 * @dest : destination
 * @src : source
 * @n : number of bytes of string
 *
 * Return : Resulting destination
 *
 */

char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0' && n > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}

	*ptr = '\0';

	return (dest);
}
