#include <stdio.h>
#include "main.h"
/**
 * print_to_98: This prints all numbers
 * from n to 98.
 * @n: This is the input
 */
void print_to_98(int n) 
{
	int i;
    
    	if (n <= 98) 
	{
		for (i = n; i <= 98; i++) 
		{
			if (i != n) 
			{
				printf(", ");
			}
			printf("%d", i);
		}
	} 
    	else 
	{
        	for (i = n; i >= 98; i--) 
        	{
            		if (i != n) 
            		{
                		printf(", ");
           	 	}
            		printf("%d", i);
       		 }
   	 }
   	 printf("\n");
}
