#include "monty.h"

/**
 * _pchar - Func print character from the top of the stack
 * @head: Head of the stack
 * @line_number: Line number
 * Return: Null
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	current = *head;

	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}

	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current->n);
}
