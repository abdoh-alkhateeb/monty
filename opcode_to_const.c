#include "monty.h"

/**
 * opcode_to_const - Maps opcode string to its corresponding integer constant.
 * @opcode: The opcode string to be mapped.
 *
 * Return: The corresponding integer constant for the opcode.
 */
int opcode_to_const(char *opcode)
{
	char *p;

	for (p = opcode; *p; ++p)
		*p = tolower(*p);

	if (strcmp(opcode, "push") == 0)
		return (PUSH);
	if (strcmp(opcode, "pall") == 0)
		return (PALL);
	if (strcmp(opcode, "pint") == 0)
		return (PINT);
	if (strcmp(opcode, "pop") == 0)
		return (POP);
	if (strcmp(opcode, "swap") == 0)
		return (SWAP);
	if (strcmp(opcode, "add") == 0)
		return (ADD);
	if (strcmp(opcode, "nop") == 0 || opcode[0] == '#')
		return (NOP);
	if (strcmp(opcode, "sub") == 0)
		return (SUB);
	if (strcmp(opcode, "div") == 0)
		return (DIV);
	if (strcmp(opcode, "mul") == 0)
		return (MUL);
	if (strcmp(opcode, "mod") == 0)
		return (MOD);
	if (strcmp(opcode, "pchar") == 0)
		return (PCHAR);
	if (strcmp(opcode, "pstr") == 0)
		return (PSTR);

	return (INVALID_OPCODE);
}
