#include "main.h"

/**
 * rev_string - a function that reverses a string
 * @s : input string 
 */

void rev_string(char *s)
{
	char temp;
	int i, len, k;

	len = 0;
	k = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	k = len - 1;

	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[k];
		s[k--] = temp;
	}
}
