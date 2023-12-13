#include "monty.h"

/**
 * enqueue - the Function that add node to the bottom of the queue.
 * @head: the Head
 * @n: new value
 * Return: Null
 */
void enqueue(stack_t **head, int n)
{
	stack_t *newNode, *currentNode;

	currentNode = *head;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->next = NULL;

	while (currentNode && currentNode->next)
	{
		currentNode = currentNode->next;
	}

	if (!currentNode)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		currentNode->next = newNode;
		newNode->prev = currentNode;
	}
}
