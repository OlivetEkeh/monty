#include "monty.h"

/**
 * execute - the function that execute the opcode
 * @content: the content
 * @head: the stack head
 * @file: the monty file 
 * @line_number: int line 
 * Return: NUll
 */

int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pchar", _pchar},
		{"sub", subs},
		{"pstr", _pstr},
		{"div", _div},
		{"mod", _mod},
		{"mul", _mul},
		{"nop", _nop},
		{"queue", _queue},
		{"stack", _stack},
		{NULL, NULL},
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
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
