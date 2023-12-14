#include "monty.h"
/**
 *subs - the function for sustration
 *@head: the Head
 *@line_number: the Integer line
 *Return: Null
 */
void subs(stack_t **head, unsigned int line_number)
{
	stack_t *auxi;
	int i, nodes;

	auxi = *head;
	for (nodes = 0; auxi != NULL; nodes++)
		auxi = auxi->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	auxi = *head;
	i = auxi->next->n - auxi->n;
	auxi->next->n = i;
	*head = auxi->next;
	free(auxi);
}
