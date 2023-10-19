#include "monty.h"

/**
 * rotl - Rotate the stack to the top.
 *
 * Return: Nothing.
 */
void rotl(void)
{
    if (stack != NULL && stack->next != NULL)
    {
        stack_t *top = stack;
        stack_t *bottom = stack;

        stack = stack->next;
        stack->prev = NULL;

        while (bottom->next != NULL)
            bottom = bottom->next;

        bottom->next = top;
        top->next = NULL;
        top->prev = bottom;
    }
}
