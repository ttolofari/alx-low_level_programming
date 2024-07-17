#include "main.h"
/**
* _isalpha - Shows 1 if the input is c
* letter else shows 0
*
* @c: The input character in ASCII code
*
* Return: Returns 1 for alphabets and 0
* for every other character
*/
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
	return (1);
	}
	else
	{
	return (0);
	}
	_putchar('\n');
}
