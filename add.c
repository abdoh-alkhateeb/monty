#include "monty.h"

/**
 * add - Adds top two elements of stack, pops them, and pushes the sum.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int add(unsigned int line_number)
{
	int sum;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	sum = top->n;
	sum += top->next->n;
	top->next->n = sum;

	top->next->prev = NULL;
	stack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
