#include <stdlib.h>
#include "main.h"

/**
 * *str_concat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 *
 * Return: pointer to the new string created (Success), or NULL (Error)
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, s1_len, s2_len;

	i = 0;
	j = 0;
	s1_len = 0;
	s2_len = 0;

	while (s1 && s1[s1_len])
	{
		s1_len++;
	}

	while (s2 && s2[s2_len])
	{
		s2_len++;
	}

	concat = malloc(sizeof(char) * (s2_len + s1_len + 1));
	
	if (concat == NULL)
	{
		return (NULL);
	}

	if (s1)
	{
		while (i < s1_len)
		{
			concat[i] = s1[i];
			i++;
		}
	}

	if (s2)
	{
		while (i < (s1_len + s2_len))
		{
			concat[i] = s2[j];
			i++;
			j++;
		}
	}
	concat[i] = '\0';

	return (concat);
}
