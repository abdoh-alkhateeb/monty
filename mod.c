#include "monty.h"

/**
 * mod - Mods top two elements of stack, pops them, and pushes remainder.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int mod(unsigned int line_number)
{
	int result;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}

	result = top->next->n % top->n;
	top->next->n = result;

	top->next->prev = NULL;
	stack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
