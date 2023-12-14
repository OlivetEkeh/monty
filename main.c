#define _GNU_SOURCE
#include "monty.h"

MontyEnv_t env;

/**
 * main - Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *content = NULL;
	size_t size = 0;
	ssize_t read_line;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	env.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_line = getline(&content, &size, file)) != -1)
	{
		content = strtok(content, "\n");
		line_number++;
		env.content = content;

		if (read_line > 0)
		{
			execute(content, &stack, line_number, file);
		}

		free(content);
		content = NULL;
	}

	free_stacks(stack);
	fclose(env.file);
	free(content);

	return (0);
}
