#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int swap(unsigned int line_number)
{
	int temp;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;

	return (EXIT_SUCCESS);
}
