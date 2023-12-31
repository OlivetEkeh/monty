#include "monty.h"

/**
 * _pint - this function prints the value of top of the stack
 * @head: the head
 * @line_number: the line integer
 * Return: Null
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
