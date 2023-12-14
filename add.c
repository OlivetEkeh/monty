#include "monty.h"

/**
 * _add - This adds two elements to the top of the stack
 * @head: The head
 * @line_number: The Integer Line
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int addition;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;
	addition = first->n + second->n;

	second->n = addition;
	*head = second;
	free(first);
}
