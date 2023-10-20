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
	global.retval = EXIT_FAILURE;
	global.str = global.operand = NULL;
	global.delim = " \n";
	global.ln = 1, global.i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(global.retval);
	}
	else
	{
		global.file = fopen(argv[1], "r");

		if (global.file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(global.retval);
		}
		process_start(&global);
		fclose(global.file);
		global.retval = EXIT_SUCCESS;
		free_node(global.head);
	}
	return (global.retval);
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
		{
			gl->ln++;
			continue;
		}
		if (gl->str[0] == '#')
			continue;
		gl->operand = strtok(NULL, gl->delim);
		if (gl->operand == NULL || strcmp(gl->operand, " ") == 0)
		{
			gl->num = 0;
			gl->temp = "";
		}
		else
		{
			checker(gl);
			if (atoi(gl->operand) != 0 || strcmp(gl->operand, "0") == 0)
			{
				gl->num = atoi(gl->operand);
			}
			else
			{
				if (gl->operand[0] == '-')
					gl->num = atoi(gl->operand);
				else
				{
					gl->num = 0;
					gl->temp = gl->operand;
				}
			}
		}
		get_opcodes(gl->str)(&gl->head, gl->ln);
		gl->temp = gl->operand = NULL;
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

/**
 * checker - checks if the operand is a number
 * @gl: global variables
 * Return: void
*/

void checker(global_t *gl)
{
	while (gl->operand[gl->i] != '\0')
	{
		if (gl->operand[gl->i] == '-' && gl->operand[gl->i + 1] != '\0')
			gl->i++;
		if (isdigit(gl->operand[gl->i]) == 0)
		{
			gl->num = 0;
			gl->temp = "";
		}
		gl->i++;
	}
	gl->i = 0;
}
