#include "main.h"
/**
* _islower - Checks if input is lowercase
* character or not. Shows 1 for lowercase
* else show 0.
*
* @c: The input character in ASCII code
*
* Return: 1 for lowercase else 0.
*/
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
	return (1);
	}
	else
	{
	return (0);
	}
	_putchar('\n');
}
