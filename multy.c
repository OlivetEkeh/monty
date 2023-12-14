#include "monty.h"
/**
 * _mul - this funtion multiplies the top two elem.
 * @head: the Head
 * @line_number: Integer line
 * Return: Null
 */
void _mul(stack_t **head, unsigned int line_number)
{
	int auxiliary;
	int size = 0;
	stack_t *h;

	h = *head;
	while (h)
	{
		h = h->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	auxiliary = h->next->n * h->n;
	h->next->n = auxiliary;
	*head = h->next;
	free(h);
}
