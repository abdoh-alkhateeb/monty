#include "monty.h"

/**
 * mul - Mults top two elements of stack, pops them, and pushes the product.
 * @line_number: The line number of the current instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int mul(unsigned int line_number)
{
	int product;
	stack_t *top = stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	product = top->next->n * top->n;
	top->next->n = product;

	top->next->prev = NULL;
	stack = top->next;
	free(top);

	return (EXIT_SUCCESS);
}
