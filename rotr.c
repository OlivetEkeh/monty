#include "monty.h"
/**
  *_rotr- this function rotates the stack
  *@head: the Head
  *@line_number: the Integer num
  *Return: Null
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	current = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = *head;
	current->prev->next = NULL;
	current->prev = NULL;
	(*head)->prev = current;
	(*head) = current;
}
