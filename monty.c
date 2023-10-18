#include "monty.h"
global_t global;

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int retval = EXIT_FAILURE;

	global.str = NULL;
	global.delim = " \n";
	global.ln = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(retval);
	}
	else
	{
		global.file = fopen(argv[1], "r");

		if (global.file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(retval);
		}
		process_start(&global);
		fclose(global.file);
		retval = EXIT_SUCCESS;
		free_node(global.head);
	}
	return (retval);
}

/**
 * process_start - function that processes the file
 * @gl: global variables
 * Return: void
 */

void process_start(global_t *gl)
{
	while (fgets(gl->ch, 1000, gl->file) != NULL)
	{
		gl->str = strtok(gl->ch, gl->delim);
		if (gl->str == NULL || strcmp(gl->str, " ") == 0 || strlen(gl->str) == 1)
			continue;
		gl->operand = strtok(NULL, gl->delim);
		if (gl->operand == NULL || strcmp(gl->operand, " ") == 0)
		{
			gl->temp = NULL;
			gl->num = 0;
		}
		else
		{
			if (atoi(gl->operand) != 0 || strcmp(gl->operand, "0") == 0)
				gl->num = atoi(gl->operand);
			else
			{
				gl->num = 0;
				gl->temp = gl->operand;
			}
		}
		get_opcodes(gl->str)(&gl->head, gl->ln);
		gl->temp = NULL;
		gl->ln++;
	}
}

/**
 * free_node - frees the stack
 * @stack: pointer to the top of the stack
 * Return: void
*/

void free_node(stack_t *stack)
{
	stack_t *traverse;

	while (stack != NULL)
	{
		traverse = stack;
		stack = stack->next;
		free(traverse);
	}
}
