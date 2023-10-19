#include "monty.h"

stack_t *stack = NULL;

/**
 * main - Entry point for the Monty ByteCodes Interpreter
 *
 * @argc: The number of command-line arguments. It should be 2: the program
 * name and the Monty bytecode file to execute.
 *
 * @argv: An array of command-line arguments, where argv[0] is the program
 * name and argv[1] is the path to the Monty bytecode file to be executed.
 *
 * Description: The Monty ByteCodes Interpreter is a program designed to
 * execute scripts written in the Monty scripting language. Monty 0.98
 * is a language that relies on a unique stack-based data structure, with
 * specific instructions for manipulating it. The interpreter reads and
 * interprets Monty bytecode files to execute various operations on the stack.
 *
 * Return: The function returns 0 on success, indicating that the script
 * was executed without errors. In case of errors, it returns 1, and error
 * messages are printed to the standard error stream.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	interpret_file(argv[1]);
	free_stack();

	return (EXIT_SUCCESS);
}
