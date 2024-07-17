#include <stdio.h>
#include "main.h"
/**
 * main - a program that prints its name
 * argc: number of arguments supplied
 * argv: the array of arguments provided
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
