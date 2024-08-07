#include <unistd.h>
#include "main.h"

/*
 * print_binary - prints the binary representation of a number
 * @n: number supplied
 *
 * Return: binary representation of the number
 */

void print_binary(unsigned long int n)
{
	int i;
	int val;

	if (n == 0)
		_putchar('0');
	for (val = 0, i = sizeof(n) * 8 - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
			val = 1;
		if (val == 1)
			((n >> i) & 1) ? _putchar('1') : _putchar('0');
	}
}
