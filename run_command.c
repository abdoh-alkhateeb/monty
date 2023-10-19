#include "monty.h"

/**
 * run_command_complement - Execute the rest of Monty bytecode commands.
 * @tokens: An array of strings containing line tokens.
 * @line_number: The line number of the current Monty bytecode instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int run_command_complement(char **tokens, unsigned int line_number)
{
	short int exit_status = EXIT_SUCCESS;

	switch (opcode_to_const(tokens[0]))
	{
	case ADD:
		exit_status = add(line_number);
		break;
	case SUB:
		exit_status = sub(line_number);
		break;
	case MUL:
		exit_status = mul(line_number);
		break;
	case DIV:
		exit_status = div_op(line_number);
		break;
	case MOD:
		exit_status = mod(line_number);
		break;
	default:
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, tokens[0]);
		exit_status = EXIT_FAILURE;
	}

	return (exit_status);
}

/**
 * run_command - Execute a Monty bytecode command.
 * @tokens: An array of strings containing line tokens.
 * @line_number: The line number of the current Monty bytecode instruction.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int run_command(char **tokens, unsigned int line_number)
{
	short int exit_status = EXIT_SUCCESS;

	switch (opcode_to_const(tokens[0]))
	{
	case PUSH:
		exit_status = push(tokens[1], line_number);
		break;
	case POP:
		exit_status = pop(line_number);
		break;
	case PINT:
		exit_status = pint(line_number);
		break;
	case PCHAR:
		exit_status = pchar(line_number);
		break;
	case PSTR:
		exit_status = pstr();
		break;
	case PALL:
		pall();
		break;
	case SWAP:
		exit_status = swap(line_number);
		break;
	case ROTR:
		rotr();
		break;
	case ROTL:
		rotl();
		break;
	case NOP:
		break;
	default:
		exit_status = run_command_complement(tokens, line_number);
	}

	return (exit_status);
}
