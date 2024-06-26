#include "main.h"

/**
 * print_sign - it returns whether +  or -
 * @n: the int to check
 * Return: 0 for the input of 0
 * 1 for values greater than 1
 * and -1 for values less than 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	} else if (n == 0)
	{
		_putchar(48);
		return (0);
	} else if (n < 0)
	{
		_putchar('-');
	}
		return (-1);
}
