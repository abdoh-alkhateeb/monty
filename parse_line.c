#include "monty.h"

/**
 * parse_line - Tokenize an input line into an array of strings.
 * @line: The input line to be tokenized.
 *
 * Return: An array of strings containing the tokens from the input line.
 * The last element of the array is set to NULL. If there is an error, it
 * returns NULL.
 */
char **parse_line(char *line)
{
	char **tokens;

	if (line == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * 2);

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tokens[0] = strtok(line, " ");
	tokens[1] = strtok(NULL, " ");

	return (tokens);
}
