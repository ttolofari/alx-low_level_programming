#include <stdio.h>
#include <stdlib.h>

/**
 * main - a function that prints the opcodes of its
 * own main function.
 * @argc: This is the number of arguments provided.
 * @argv: This is the array of arguments.
 *
 * Return: 0 on Success, or error on failure.
 */
int main(int argc, char *argv[])
{
	int byte_num;
	unsigned char *main_start = (unsigned char *)main;
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	byte_num = atoi(argv[1]);
	
	if (byte_num < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < byte_num; i++)
	{
		printf("%02x", main_start[i]);
		if (i < byte_num - 1)
		{
			printf(" ");
		}
	}
	printf("\n");

	return (0);
}
