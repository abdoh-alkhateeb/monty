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
	char *line = NULL, *p;
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
		p = strchr(line, '\n');

		if (p)
			*p = '\0';

		if (strlen(line) == 0)
			continue;

		tokens = parse_line(line);

		if (tokens[0] == NULL)
			continue;

		exit_status = run_command(tokens, line_number);
		free(tokens);

		if (exit_status == EXIT_FAILURE)
			free_stack(), exit(EXIT_FAILURE);
	}

	free(line);
	free_stack();
	fclose(fp);
}
