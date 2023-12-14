#include "monty.h"

/**
 * pall - this functions prints stack info
 * @head: the Head
 * @line_number: the Integer line
 * Return: Null
 */
void _pall(stack_t **head, unsigned int line_number)
{
        stack_t *value;
        (void)line_number;

        value = *head;
        if (value == NULL)
        {
                return;
        }

        while (value)
        {
                printf("%d\n", value->n);
                value = value->next;
        }
}
