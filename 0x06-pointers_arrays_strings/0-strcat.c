#include "main.h"

/**
 * *_strcat - function to concatenate two strings
 * @*dest :  destination
 * @*src :  source
 *
 * Return : pointer to the resultant string
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';


	return (dest);
}
