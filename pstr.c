#include "monty.h"

/**
 * pstr - Prints the string starting from the top of the stack.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int pstr(void)
{
	stack_t *top = stack;

	while (top != NULL && top->n != 0 && isascii(top->n))
	{
		putchar(top->n);
		top = top->next;
	}

	putchar('\n');

	return (EXIT_SUCCESS);
}
