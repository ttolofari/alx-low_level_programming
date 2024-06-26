#include "main.h"

/**
 * print_last_digit - Shows the last digit of a number
 * @i: the input value
 * Return: last digit
 */
int print_last_digit(int i)
{
	int a;

	if (i < 0)
		i = -i;

	a = i % 10;

	if (a < 0)
		i = -i;

	_putchar(a + '0');

	return (a);
}
