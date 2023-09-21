#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;

	/*
	 * Write your line of code here...
	 * Remember:
	 * - You are not allowed to use 'a'
	 * - You are not allowed to modify 'p'
	 * - Use only one statement
	 * - You are not allowed to code anything else than this line of code
	 */
	*(p + 5) = 98; /* Set the value of p to 98 */

	/* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
	return (0);
}

