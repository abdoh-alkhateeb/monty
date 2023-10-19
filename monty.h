#ifndef _MONTY_H_
#define _MONTY_H_

#define PUSH 0
#define PALL 1
#define PINT 2
#define POP 3
#define SWAP 4
#define ADD 5
#define NOP 6
#define SUB 7
#define DIV 8
#define MUL 9
#define MOD 10
#define PCHAR 11
#define PSTR 12
#define ROTL 13
#define ROTR 14
#define STACK 15
#define QUEUE 16
#define INVALID_OPCODE -1

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *stack;

void interpret_file(char *filename);
char **parse_line(char *line);
bool is_integer(char *str);
int opcode_to_const(char *opcode);
int run_command(char **tokens, unsigned int line_number);
void free_stack(void);

int push(char *integer, unsigned int line_number);
int pop(unsigned int line_number);
int pint(unsigned int line_number);
int pchar(unsigned int line_number);
int pstr(void);
void pall(void);
void rotr(void);
void rotl(void);
int swap(unsigned int line_number);
int add(unsigned int line_number);
int sub(unsigned int line_number);
int mul(unsigned int line_number);
int div_op(unsigned int line_number);
int mod(unsigned int line_number);

#endif /* _MONTY_H_ */
