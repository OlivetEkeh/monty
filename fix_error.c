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
