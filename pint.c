#include "monty.h"

/**
 * pint - Print the value at the top of the stack, followed by a new line.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int pint(unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}

	printf("%d\n", stack->n);

	return (EXIT_SUCCESS);
}
