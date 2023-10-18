#include "monty.h"

/**
 * get_opcodes - function that selects the correct function to perform
 * @opcode: opcode to be evaluated
 * Return: pointer to the function that corresponds to the opcode
 */

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
			return (opcodes[counter].f);
		counter++;
	}
	return (NULL);
}

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: pushes an element to the stack
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (global.temp != NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->n = global.num;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: prints all the values on the stack
*/

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

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: prints the value at the top of the stack
*/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", traverse->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: removes the top element of the stack
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
