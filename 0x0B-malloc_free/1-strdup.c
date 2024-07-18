#include <stdlib.h>
#include "main.h"

/**
 * *_strdup - copies the string given as parameter
 * @str: string to duplicate
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(char *str)
{
	char *duplicate;
	int i, str_len;

	i = 0;
	str_len = 0;
	
	if (str == NULL)
	{
		return (NULL);
	}

	while (str[str_len])
	{
		str_len++;
	}

	duplicate = malloc((str_len + 1) * sizeof(char));

	if (duplicate == NULL)
	{
		return (NULL);
	}

	while ((duplicate[i] = str[i]) != '\0')
	{
		i++;
	}

	return (duplicate);
}

