#include "main.h"

/**
 * print_last_digit - Shows the last digit of a number
 * @n: the input value
 * Return: last digit
 */
int print_last_digit(int i)
{
	int num;

	num = i % 10;

	_putchar(num);

	return (num);
}
