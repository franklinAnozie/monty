#ifndef _MONTY_H_
#define _MONTY_H_

/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stddef.h>

/* Structures */

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @num: integer
 * @head: pointer to the top of the stack
 * @temp: pointer to the string
 * @ch: character
 * @file: pointer to the file
 * @str: pointer to the string
 * @delim: pointer to the string
 * @operand: pointer to the string
 * @ln: unsigned integer
 * Description: global variables
 * for stack, queues, LIFO, FIFO
*/
typedef struct global_s
{
	int num;
	char ch[1000];
	FILE *file;
	char *str;
	char *delim;
	char *operand;
	unsigned int ln;
	stack_t *head;
	char *temp;
	int choice;
} global_t;

/* Global variables */
extern global_t global;

/* Prototypes */
void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void process_start(global_t *gl);
void free_node(stack_t *stack);

#endif /* _MONTY_H_ */
