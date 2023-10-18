#include "shell.h"
/**
 * main - The main funtion of my simple shell project
 * @argc: the argument count
 * @argv: the argument vector
 * @envp: the environment variable
 *
 * Return: Returns 0 in success
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t n = 0;

	(void)argc, (void)argv;

	while (1)
	{
		display_prompt();

		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(1);
		}

		char **args = parse_command(line);

		if (strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			free(line);
			exit(0);
		}
		else if (strcmp(args[0], "env") == 0 && args[1] == NULL)
		{
			int j = 0;
			while (envp[j] != NULL)
			{
				write(STDOUT_FILENO, envp[j], strlen(envp[j]));
				write(STDOUT_FILENO, "\n", 1);
				j++;
			}
		}
		else
		{
			execute_command(args);
		}
		free_args(args);
	}
	return (0);
}
