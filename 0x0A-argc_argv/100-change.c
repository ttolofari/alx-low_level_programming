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
 * main - prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	
	int cents, num_coins, count, i;
	int coins[] =  {25, 10, 5, 2, 1};
	
	
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = _myatoi(argv[1]);
	count = 0;


	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5 && cents >= 0; i++)
	{
		while (cents >= coins[i])
		{
			count ++;
			cents -= coins[i];
		}
	}

	printf("%d\n", count);
	return (0);
}



