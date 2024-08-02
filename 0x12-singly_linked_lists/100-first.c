#include <stdio.h>
/**
 * initializer - prints a comment before main is initialized
 */

void __attribute__((constructor)) initializer(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

