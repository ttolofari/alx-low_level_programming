#include "main.h"

/**
 * print_last_digit - Shows the last digit of a number
 * @i: the input value
 * Return: last digit
 */
int print_last_digit(int i)
{
	int a;

	a = i % 10;

	if (i < 0)
	{
		_putchar(-i + 48);
	return (-i);
	}

	else
	{
	_putchar(i+48);
	return (i);
	}
}
