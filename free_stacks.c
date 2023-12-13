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
