#include "monty.h"

/**
 * interpret_file - Read and interpret Monty commands from a file.
 * @filename: The name of the Monty bytecode file to interpret.
 *
 * Return: Nothing.
 */
void interpret_file(char *filename)
{
	FILE *fp;
	char *line = NULL;
	char **tokens;
	int exit_status;
	size_t line_length = 1024, line_number;

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	for (line_number = 1; getline(&line, &line_length, fp) != EOF; line_number++)
	{
		if (strlen(line) == 0 || line[0] == '\n')
			continue;

		tokens = parse_line(line);
		exit_status = run_command(tokens, line_number);

		free(tokens);

		if (exit_status == EXIT_FAILURE)
		{
			free_stack();
			exit(EXIT_FAILURE);
		}
	}

	if (line != NULL)
		free(line);

	fclose(fp);
}
