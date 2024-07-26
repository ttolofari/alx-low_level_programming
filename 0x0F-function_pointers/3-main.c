#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - This function provides simmple operation
 * based on the arguments provided in the commandline.
 * @argc : This is the number of arguments
 * @argv : This the array argument provided
 *
 * Return : 0 on Success, or error on failure
 */
int main(int argc, char *argv[])
{
	int (*oprt)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	oprt = get_op_func(argv[2]);

	if (!oprt)
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", oprt(atoi(argv[1]), atoi(argv[3])));
	return (0);
}
