#include <stdio.h>
#include "main.h"


/**
 * _myatoi - converts a string to integer
 * @s: input string
 *
 * Return: the resultant integer
 */
int _myatoi(char *s)
{
	int result;
	int q;
	int p;

	result = 0;
	q = 1;
	p = 0;

	while (s[p] == ' ')
	{
		p++;
	}

	if (s[p] == '-' ||  s[p] == '+')
	{
		q = (s[p++] == '-') ? -1 : 1;
	}

	while (s[p] >= '0' && s[p] <= '9')
	{
		result = result * 10 + (s[p++] - '0');
	}

	return (result * q);
}

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	int i = _myatoi(argv[1]);
	int j = _myatoi(argv[2]);
	int k = i * j;

	printf("%d\n", k);

	return (0);
}

