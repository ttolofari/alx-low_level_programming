#include <stdio.h>

/**
 * add - adds two integers
 * @a: First integer
 * @b: Second integer
 * Return: The sum of a and b
 */
int add(int a, int b)
{
    return a + b;
}

/**
 * sub - subtracts two integers
 * @a: First integer
 * @b: Second integer
 * Return: The difference of a and b
 */
int sub(int a, int b)
{
    return a - b;
}

/**
 * mul - multiplies two integers
 * @a: First integer
 * @b: Second integer
 * Return: The product of a and b
 */
int mul(int a, int b)
{
    return a * b;
}

/**
 * div - divides two integers
 * @a: First integer
 * @b: Second integer
 * Return: The quotient of a and b
 */
int div(int a, int b)
{
    if (b == 0) {
        return 0;
    }
    return a / b;
}

/**
 * mod - computes the modulus of two integers
 * @a: First integer
 * @b: Second integer
 * Return: The modulus of a and b
 */
int mod(int a, int b)
{
    if (b == 0) {
        return 0;
    }
    return a % b;
}

