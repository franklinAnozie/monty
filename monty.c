#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int retval = EXIT_FAILURE;
	stack_t *head = NULL;
	char *str = NULL, *delim = " \n";
	char *str_update[2];
	int i = 0, n;
	unsigned int ln = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (retval);
	}
	else
	{
		FILE *file = fopen(argv[1], "r");

		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit (retval);
		}

		char ch[1000];

		while (fgets(ch, 1000, file) != NULL)
		{
			str = strtok(ch, delim);
			while (str != NULL)
			{
				if (strcmp(str, " ") == 0)
					break;
				else
				{
					if (i >= 2)
					{
						i = 0;
						break;
					}
					strcpy(str_update[i], str);
					str = strtok(NULL, delim);
					i++;
				}
			}
			i = 0;
			if (atoi(str_update[1]) != 0 || strcmp(str_update[1], "0") == 0)
				n = atoi(str_update[1]);
			get_opcodes(str_update[0])(&head, ln);
			ln++;
		}
		fclose(file);
		retval = EXIT_SUCCESS;
	}
	return (retval);
}
