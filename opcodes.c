#include "monty.h"

void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
    instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
    int counter = 0;

    while (opcodes[counter].opcode != NULL)
    {
        if (*opcodes[counter].opcode == *opcode)
            return (opcodes[counter].f);
        counter++;
    }

    return (NULL);
}
void push(stack_t **stack, unsigned int line_number)
{  
    stack_t *new_node;
    stack_t **head = stack;
    int n;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        free(new_node);
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
        *head = new_node;
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *traverse = *stack;
    (void) line_number;
    
    if (stack == NULL)
        exit(EXIT_SUCCESS);
    else
    {
        while (traverse != NULL)
        {
            printf("%d\n", traverse->n);
            traverse = traverse->next;
        }
    }
}