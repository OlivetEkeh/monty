#include "monty.h"

/**
 * execute - the function that execute the opcode
 * @content: the content
 * @head: the stack head
 * @file: the monty file 
 * @line_number: int line 
 * Return: 0 on success, 1 on failure
 */

int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pchar", _pchar},
		{"sub", subs},
		{"pstr", _pstr},
		{"div", _div},
		{"mod", _mod},
		{"pall", pall},
		{"mul", _mul},
		{"nop", _nop},
		{"queue", _queue},
		{"stack", _stack},
		{NULL, NULL},
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, "\n\t");
	if (op && env.arg && env.arg[0] == '#')
	{
		return (0);
	}

	env.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(content);
		free_stacks(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
