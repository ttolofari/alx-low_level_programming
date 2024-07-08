#include "main.h"

/**
 * *_strspn - gets the length of a prefix substring
 * @s: lookup string
 * @accept: second string
 *
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int k, l, count;

	count = 0;
	for (k = 0; s[k] != '\0'; k++)
	{
		for (l = 0; accept[l] != '\0' && accept[l] != s[k]; l++)
			;
		if (s[k] == accept[l])
			count++;
		if (accept[l] == '\0')
			return (count);
	}
	return (count);
}
