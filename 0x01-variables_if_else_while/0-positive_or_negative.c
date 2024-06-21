#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 *
 */


int main(void) 
{
    int n;
    
    // Seed the random number generator
    srand(time(0));
    
    // Generate a random number between INT_MIN and INT_MAX
    n = rand() - RAND_MAX / 2;
    
    // Determine if n is positive, zero, or negative
    printf("The number %d ", n);
    
    if (n > 0) 
        printf("is positive\n");
    else if (n == 0) 
        printf("is zero\n");
    else 
        printf("is negative\n");
    
    
    return 0;
}

