#include "shell.h"
/**
 * parse_commands - parses based on semi-colons
 * @line: the line of the command
 *
 * Return: the commands
 */
#define MAX_COMMANDS 100
char **parse_commands(char *line)
{
	char **commands = malloc(MAX_COMMANDS * sizeof(char *));
	char *token = strtok(line, ";");
	int index = 0;

	while (token != NULL)
	{
		commands[index] = strdup(token);
		if (commands[index] == NULL)
		{
			perror("Memory allocation");
			exit(0);
		}
		index++;
		token = strtok(NULL, ";");
	}
	commands[index] = NULL;
	return (commands);
}
