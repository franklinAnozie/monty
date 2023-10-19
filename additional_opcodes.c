#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: rotates the stack to the bottom
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: sets the format of the data to a stack (LIFO)
*/

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.choice = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 * Description: sets the format of the data to a queue (FIFO)
*/

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.choice = 1;
}
