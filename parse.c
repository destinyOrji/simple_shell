#include "shell.h"
/**
 * parse_command - parses the input to my command line
 * @line: the input to the command line
 *
 * Return: returns the parsed commands
 */
#define MAX_BUFF 100
char **parse_command(char *line)
{
	char **args = malloc(sizeof(char *) * MAX_BUFF);
	int i = 0;
	char *token = strtok(line, " \n");

	while (token)
	{
		args[i] = strdup(token);
		token = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL;
	return args;
}
