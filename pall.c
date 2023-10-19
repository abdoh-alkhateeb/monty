#include "monty.h"

/**
 * pall - Prints all the elements of the stack.
 *
 * Return: Nothing.
 */
void pall(void)
{
	stack_t *top = stack;

	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
