#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int pchar(unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}

	if (isascii(stack->n))
	{
		putchar(stack->n);
		putchar('\n');
		return (EXIT_SUCCESS);
	}

	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	return (EXIT_FAILURE);
}
