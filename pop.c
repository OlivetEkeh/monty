#include "monty.h"

/**
 * pop - the function that prints the top
 * @head: the head
 * @line_number: the line integer
 * REturn: Null
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *value;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	value = *head;
	*head = value->next;
	free(value);
}
