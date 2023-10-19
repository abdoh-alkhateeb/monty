#include "monty.h"

/**
 * free_stack - Frees the memory allocated for the stack.
 *
 * Return: Nothing.
 */
void free_stack(void)
{
	stack_t *top;

	while (stack != NULL)
	{
		top = stack;
		stack = stack->next;
		free(top);
	}
}
