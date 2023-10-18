#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number),
		exit(EXIT_FAILURE);
	}
	else
	{
		temp  = *stack;
		next = (*stack)->next;
		next->next->prev = temp;
		temp->next = temp->next->next;
		temp->prev = next;
		next->next = temp;
		next->prev = NULL;
		*stack = next;
	}
}

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum = 0, count = 0;

	if (*stack == NULL)
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
		*stack = temp;
		free(temp->prev);
	}
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
