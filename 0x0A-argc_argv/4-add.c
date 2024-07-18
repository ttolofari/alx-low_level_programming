#include <stdio.h>
#include "main.h"

/**
 * _myatoi - converts a sting to an integer
 * @s: supplied string
 *
 * Return: the resultant int, or 0 if not
 */
int _myatoi(char *s)
{
	int i, sign, result, digit;

	i = 0;
	sign = 1;
	result = 0;

	while (s[i] == ' ')
		i++;

	if (s[i] ==  '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			result = result * 10 + digit;
		}
		else
		{
			break;
		}
		i++;
	}
	
	return (sign * result);
}

/**
 * main - adds positive numbers passed as command-line arguments
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, j, k, sum, num;

	sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				puts("Error");
				return (1);
			}
		}
	}

	for (k = 1; k < argc; k++)
	{
		num = _myatoi(argv[k]);
		if (num >= 0)
		{
			sum += num;
		}
	}

	printf("%d\n", sum);
	return (0);
}

