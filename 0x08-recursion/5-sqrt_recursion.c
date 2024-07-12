#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * _sqrt_helper - helper function for the square root
 * @n: number to calculate the square root of
 * @start: starting point of search
 * @end : ending point of search
 *
 * Return: the resulting square root
 */
int _sqrt_helper(int n, int start, int end)
{
	int mid;
	int square;

	if (start > end)
	{
		return (-1);
	}
	mid = (start + end) / 2;
	square = mid * mid;

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

/**
 * _sqrt_helper - helper function for the square root
 * @start: starting point of search
 * @end : ending point of search
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 0, n));
}
