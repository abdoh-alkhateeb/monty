#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char *line, *token;
	size_t i, j;
	size_t input_size = 1024, read_size;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	for (i = 1; read_size = getline(&line, &input_size, file) != EOF; i++)
	{
		if (read_size > 0 && line[read_size - 1] == '\n')
			line[read_size - 1] = '\0';

		token = strtok(line, " ");
		for (j = 0; token != NULL && j < 2; j++)
		{
			printf("Line %d | Token %d: %s\n", i, j, token);
			token = strtok(NULL, " ");
		}
	}

	fclose(file);
	free(line);

	return (0);
}
