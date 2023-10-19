#include "monty.h"

/**
 * rotl - Rotate the stack to the bottom.
 *
 * Return: Nothing.
 */
void rotr(void)
{
    if (stack != NULL && stack->next != NULL)
    {
        stack_t *bottom = stack;

        while (bottom->next != NULL)
            bottom = bottom->next;

        bottom->prev->next = NULL;
        bottom->next = stack;
        bottom->prev = NULL;

        stack->prev = bottom;
        stack = bottom;
    }
}
