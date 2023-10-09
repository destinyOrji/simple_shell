#include "main.h"
/**
 * main - the entry point of my simple shell program
 * @argc: the argument count
 * @argv: the argument vectors
 * @envp: the environment variables
 *
 * Return: returns 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL, *cmd_token;
	ssize_t cmd_line_input = 0;
	size_t n = 0;

	while (1)
	{
		printf("Kalmin's shell$ ");
		cmd_line_input = getline(&line, &n, stdin);

		if (cmd_line_input == -1)
		{
			perror("getline:(");
			free(line);
			return (1);
		}
		if (line[cmd_line_input - 1] == '\n')
			line[cmd_line_input - 1] = '\0';

		cmd_token = strtok(line, " ");

		if (cmd_token != NULL)
		{
			if (strcmp(cmd_token, "exit") == 0)
			{
				free(line);
				return (0);
			}
		}
	}
	return (0);
}
