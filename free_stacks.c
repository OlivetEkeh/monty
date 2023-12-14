#include "monty.h"
/**
 * free_stacks - the fuction that frees the list
 * @head: the Head
 */
void free_stacks(stack_t *head)
{
	stack_t *auxi;

	auxi = head;
	while (head)
	{
		auxi = head->next;
		free(head);
		head = auxi;
	}
}


mod.c

#include "monty.h"
/**
 * _mod - this funtion computes the division
 * @head: The Head stack
 * @line_number: Integer line
 * Return: Null
 */
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int auxiliary;
	int size = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	auxiliary = h->next->n % h->n;
	h->next->n = auxiliary;
	*head = h->next;
	free(h);
}
