#include "monty.h"

/**
 * push - the function to add nodes on the stack
 * @head: the head stack
 * @line_number: the line integer
 */

void push(stack_t **head, unsigned int line_number)
{
	size_t i;
	int value;

	if (!env.arg || *env.arg)
	{
		if (*head == NULL)
		{
			return;
		}
		handle_error(line_number, head);
	}
	for (i = (env.arg[0] == '-'); env.arg[i]; ++i)
	{
		if (!isdigit(env.arg[1]))
		{
			handle_error(line_number, head);
		}
	}

	value = atoi(env.arg);
	if (env.lifo == 0)
	{
		pushTOStack(head, value);
	}
	else
	{
		enqueue(head, value);
	}
}


/**
 * pall - this functions prints stack info
 * @head: the Head
 * @line_number: the Integer line
 * Return: Null
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *value;
	(void)line_number;

	value = *head;
	if (value == NULL)
	{
		return;
	}

	while (value)
	{
		printf("%d\n", value->n);
		value = value->next;
	}
}
