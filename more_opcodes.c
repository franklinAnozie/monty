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
	next = (*stack)->next;
	next->next->prev = temp;
	temp->next = temp->next->next;
	temp->prev = next;
	next->next = temp;
	next->prev = NULL;
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
	else
	{
		temp  = *stack;
		while (temp->next != NULL)
		{
			count++;
			temp = temp->next;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number),
			exit(EXIT_FAILURE);
		}
		while (temp->prev->prev != NULL)
		{
			temp = temp->prev;
		}
		sum = temp->n + temp->prev->n;
		temp->n = sum;
		temp->prev = NULL;
		free(temp->prev);
		*stack = temp;
	}
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
