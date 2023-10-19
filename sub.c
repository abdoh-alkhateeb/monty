#include "monty.h"

/**
 * sub - Subtracts top two elements of stack, pops them, and pushes difference.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int sub(unsigned int line_number)
{
	int difference;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	difference = top->n;
	difference = top->next->n - difference;
	top->next->n = difference;

	top->next->prev = NULL;
	stack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
