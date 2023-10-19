#include "monty.h"

/**
 * div_op - Divides top two elements of stack, pops them, and pushes quotient.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int div_op(unsigned int line_number)
{
	int quotient;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}

	quotient = top->next->n / top->n;
	top->next->n = quotient;

	top->next->prev = NULL;
	stack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
