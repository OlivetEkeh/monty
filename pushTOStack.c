#include "monty.h"

/**
 * pushTOStack - The Function that adds the node
 * @head: the Head
 * @new_value: the new value
 * Return: Null
 */
void pushTOStack(stack_t **head, int n)
{
	stack_t *elem, *aux;

	aux = *head;
	elem = malloc(sizeof(stack_t));
	if (elem == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (aux)
		aux->prev = elem;

	elem->n = n;
	elem->next = *head;
	elem->prev = NULL;
	*head = elem;
}
