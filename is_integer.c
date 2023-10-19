#include "monty.h"

/**
 * is_integer - Check if a string represents an integer.
 * @str: String to be checked.
 *
 * Return: true if the string is an integer, false otherwise.
 */
bool is_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);

		str++;
	}

	return (true);
}
