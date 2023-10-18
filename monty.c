#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int num;
stack_t *head = NULL;
char *temp = NULL;

int main(int argc, char *argv[])
{
	int retval = EXIT_FAILURE;
	char *str = NULL, *delim = " \n", *operand, ch[1000];
	unsigned int ln = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(retval);
	}
	else
	{
		FILE *file = fopen(argv[1], "r");

		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(retval);
		}
		while (fgets(ch, 1000, file) != NULL)
		{
			str = strtok(ch, delim);
			if (str == NULL || strcmp(str, " ") == 0 || strlen(str) == 1)
				continue;
			operand = strtok(NULL, delim);
			if (operand == NULL || strcmp(operand, " ") == 0)
			{
				temp = NULL;
				num = 0;
			}
			else
			{
				if (atoi(operand) != 0 || strcmp(operand, "0") == 0)
					num = atoi(operand);
				else
				{
					num = 0;
					temp = operand;
				}
			}
			get_opcodes(str)(&head, ln);
			temp = NULL;
			ln++;
		}
		fclose(file);
		(void)num;
		retval = EXIT_SUCCESS;
	}
	return (retval);
}
