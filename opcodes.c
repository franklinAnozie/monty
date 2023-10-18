#include "monty.h"

void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int counter = 0;

	while (opcodes[counter].opcode != NULL)
	{
		if (strcmp(opcodes[counter].opcode, opcode) == 0)
		{
			return (opcodes[counter].f);
		}
		counter++;
	}

	return (NULL);
}

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		exit(EXIT_FAILURE);
	}
	if (temp != NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;
	(void)line_number;

	while (traverse != NULL)
	{
		printf("%d\n", traverse->n);
		traverse = traverse->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number),
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", traverse->n);
	}
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number),
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
