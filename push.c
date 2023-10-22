#include "monty.h"

/**
 * push - Push an integer onto the stack.
 * @integer: The integer to push onto the stack as a string.
 * @line_number: The line number of the current Monty bytecode instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int push(char *integer, unsigned int line_number)
{
	stack_t *new_node;

	if (integer == NULL || is_integer(integer) == false)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}

	new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	new_node->n = atoi(integer);
	new_node->prev = NULL;

	if (stack != NULL)
		stack->prev = new_node;

	new_node->next = stack;
	stack = new_node;

	return (EXIT_SUCCESS);
}
