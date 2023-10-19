#include <stdio.h>

/* Function marked as a constructor to print messages before main */
void first(void) __attribute__ ((constructor));

/**
 * first - Prints the messages "You're beat! and yet, you must allow,"
 * and "I bore my house upon my back!" before main.
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I carry my home upon my back!\n");
}

int main(void)
{
    /* Rest of your main function code */

	return (0);
}

