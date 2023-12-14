#include "monty.h"
/**
 * _div - This function divides the top two elements
 * @head: The Head
 * @line_number: Integer line
 * Return: Null
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int size = 0; 
	int auxiliary;

	h = *head;
	while (h)
	{
		h = h->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	auxiliary = h->next->n / h->n;
	h->next->n = auxiliary;
	*head = h->next;
	free(h);
}
