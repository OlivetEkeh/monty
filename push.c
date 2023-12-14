#include "monty.h"

/**
 * handle_error - function to fix and handle errors
 * @line_number: the Int line
 * @head: the Head
 */
void handle_error(unsigned int line_number, stack_t **head)
{
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(env.file);
        free(env.content);
        if (*head != NULL)
        {
                free_stacks(*head);
        }

        exit(EXIT_FAILURE);
}

/**
 * push - the function to add nodes on the stack
 * @head: the head stack
 * @line_number: the line integer
 */

void _push(stack_t **head, unsigned int line_number)
{
	size_t i;
	int value;

	if (!env.arg || !*env.arg)
	{
		if (*head == NULL)
		{
			return;
		}
		handle_error(line_number, head);
	}
	for (i = (env.arg[0] == '-'); env.arg[i]; ++i)
	{
		if (!isdigit(env.arg[i]))
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
