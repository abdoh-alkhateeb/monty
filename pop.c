#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int pop(unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}

	top = stack;
	stack = stack->next;

	if (stack != NULL)
		stack->prev = NULL;

	free(top);

	return (0);
}
