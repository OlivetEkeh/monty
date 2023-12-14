#include "monty.h"

/**
 * _rotl - Func rotates stack to the left
 * @head: Head of the stack
 * @line_number: Line number (unused in this function)
 * Return: Null
 */
void _rotl(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *first_element = *head, *second_element;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	second_element = (*head)->next;
	second_element->prev = NULL;

	while (first_element->next != NULL)
	{
		first_element = first_element->next;
	}

	first_element->next = *head;
	(*head)->next = NULL;
	(*head)->prev = first_element;
	(*head) = second_element;
}
