#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **head, unsigned int line_number);
} instruction_t;

typedef struct MontyEnv
{
	char *arg;
	FILE *file;
	char *content;
	int lifo;
} MontyEnv_t;

extern MontyEnv_t env;

int main(int argc, char *argv[]);
void pint(stack_t **head, unsigned int line_number);
void push(stack_t **head, unsigned int line_number);
int execute(char *content, stack_t **head, unsigned int line_number, FILE *file);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void free_stacks(stack_t *head);
void _queue(stack_t **head, unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);
void handle_error(unsigned int line_number, stack_t **head);
void enqueue(stack_t **head, int n);
void pushTOStack(stack_t **head, int n);
void pall(stack_t **head, unsigned int line_number);
void subs(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, __attribute__((unused)) unsigned int line_number);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);




#endif
