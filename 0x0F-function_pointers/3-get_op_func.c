#include "3-calc.h"
#include <stdlib.h>
/**
 * get_op_func - A function that selects the correct function
 * to perform the operation asked by the user.
 * @s: The operator passed as argument.
 *
 * Return: A pointer to the function
 * corresponding to the operator, or NULL if no match.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
	};
	int i;

	i =  0;

	while (ops[i].op != NULL)
	{
		if (*(ops[i].op) == *s && *(s + 1) == '\0')
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
