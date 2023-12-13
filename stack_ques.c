#include "monty.h"
/**
 * _stack - this prints top of the stack
 * @head: the head
 * @line_number: the  Integer line
 * Return: Null
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	env.lifo = 0;
}
/**
 * _queue - prints the top of the queue
 * @head: the head
 * @line_number: Int line
 * Return: Null
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	env.lifo = 1;
}
