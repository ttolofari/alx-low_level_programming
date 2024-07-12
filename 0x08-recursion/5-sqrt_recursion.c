#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: the resulting square root
 */
int _sqrt_helper(int n, int start, int end)
{
	if (start > end)
	{
		return (-1);
	}
	
	int mid;
	long long square;
       
	mid = (start + end) / 2;
	square = (long long)mid * mid;

	if (square == n)
	{
		return (mid);
	}
	else if (square < n)
	{
		return (_sqrt_helper(n, mid + 1, end));
	}
	else
	{
		return (_sqrt_helper(n, start, mid - 1));
	}
}

int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 0, n));
}
