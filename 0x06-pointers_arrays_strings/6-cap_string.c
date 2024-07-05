#include "main.h"

/**
 * cap_string - function to capitalize all words
 * of a string
 * @str : input character
 *
 * Return : string
 */

char *cap_string(char *str)
{
	int capp = 1;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == ',' || str[i] == ';' || str[i] == '.' ||
				str[i] == '!' || str[i] == '?' || str[i] == '"' ||
				str[i] == '(' || str[i] == ')' || str[i] == '{' ||
				str[i] == '}')
		{
			capp = 1;
		}
		else if (capp && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
			capp = 0;
		}
		else
		{
			capp = 0;
		}
	}

	return (str);
}
