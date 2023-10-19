#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: swaps the top two elements of the stack
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	}
	temp  = *stack;
	next = temp->next;
	temp->next = next->next;
	next->next = temp;
	temp->prev = next;
	next->prev = NULL;
	next->next = temp;
	*stack = next;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: adds the top two elements of the stack
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum = 0, count = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
}

/**
 * nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: does nothing
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: subtracts the top two elements of the stack
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int diff = 0, count = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	*stack = temp->next;
	free(temp);
}
