#include "monty.h"

/**
 * swap - the function that add the two top elements.
 * @head: Head
 * @line_number: the line integer
 * Return: Null
 */
void swap(stack_t **head, unsigned int line_number)
{
	int tem;
	stack_t *first, *second;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;
	tem = first->n;

	first->n = second->n;
	second->n = tem;
}
