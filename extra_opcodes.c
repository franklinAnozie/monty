#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: multiplies the top two elements of the stack
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mul = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	mul = temp->n * temp->next->n;
	temp->next->n = mul;
	*stack = temp->next;
	free(temp);
}

/**
 * mod - computes the modulus of the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: computes the modulus of the top two elements of the stack
*/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number),
		exit(EXIT_FAILURE);
	}
	mod = temp->next->n % temp->n;
	temp->next->n = mod;
	*stack = temp->next;
	free(temp);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: prints the char at the top of the stack
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int ascii = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number),
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	ascii = temp->n;
	if (ascii < 0 || ascii > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number),
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ascii);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: prints the string starting at the top of the stack
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int ascii = 0;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: rotates the stack to the top
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *next;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	next = temp->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = next;
	(*stack)->prev = NULL;
}
