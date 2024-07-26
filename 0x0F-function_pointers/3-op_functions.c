#include "3-calc.h"

/**
 * op_add - This function adds two numbers.
 * @a : This is the first number
 * @b : This is the second number
 *
 * Return : The sum of both numbers
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - This function subtracts
 * the second number from the first number.
 * @a : This is the first number
 * @b : This is the second number
 *
 * Return : The difference between both numbers
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - This function multiplies two numbers.
 * @a : This is the first number
 * @b : This is the second number
 *
 * Return : The product of both numbers
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - The function divides the first nummber
 * by the second.
 * @a : This is the first number
 * @b : This is the second number
 *
 * Return : The result of the division of a by b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - This function calculates the remainder
 * of the division of the first number by the second number.
 * @a : This is the first number
 * @b : This is the second number
 *
 * Return : The remainder of the modulos division
 */
int op_mod(int a, int b)
{
	return (a % b);
}
