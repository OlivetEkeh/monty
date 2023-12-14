#include "monty.h"

/**
 * _pstr - Func prints the string from the top of the stack
 * @head: Head of the stack
 * @line_number: Line number (unused in this function)
 * Return: Null
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *head;

	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
