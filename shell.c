#include "shell.h"
/**
 * main - The main funtion of my simple shell project
 * @argc: the argument count
 * @argv: the argument vector
 * @envp: the environment variable
 *
 * Return: Returns 0 in success
 */

int main(int argc, char **argv, char **envp);
int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t n = 0;
	int j;
	char **args = NULL;

	(void)argc, (void)argv;
	while (1)
	{
		display_prompt();

		if (_getline(stdin, &line, &n) == -1)
		{
			free(line);
			exit(0);
		}

		args = parse_command(line);

		if (args == NULL || args[0] == NULL)
		{
			free(line);
			free_args(args);
			continue;
		}

		if (_strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			free(args);
			free(line);
			exit(0);
		}
		else if (_strcmp(args[0], "env") == 0 && args[1] == NULL)
		{
			j = 0;
			while (envp[j] != NULL)
			{
				write(STDOUT_FILENO, envp[j], _strlen(envp[j]));
				write(STDOUT_FILENO, "\n", 1);
				j++;
			}
		}
		else
		{
			execute_command(args, envp);
		}
		free_args(args);
		free(args);
	}
	free(line);
	return (0);
}
