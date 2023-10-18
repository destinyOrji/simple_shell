#include "main.h"
/**
 * main - the entry point of my simple shell program
 * @argc: the argument count
 * @argv: the argument vectors
 * @envp: the environment variables
 *
 * Return: returns 0 on success
 */

int main(int argc, char **argv, char **envp);
int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	char *cmd_token;
	ssize_t cmd_line_input = 0;
	size_t n = 0;
	pid_t child_p;
	char **cmd_args = NULL;
	int i, j = 0;
	int status;
	char nl = '\n';

	(void)argc, (void)argv;
	while (1)
	{
		i = 0;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		cmd_line_input = getline(&line, &n, stdin);

		if (cmd_line_input == -1)
		{
			free(line);
			exit(18);
		}

		cmd_args = malloc(sizeof(char *) * 1024);
		cmd_token = strtok(line, " \n");

		while (cmd_token)
		{
			cmd_args[i] = cmd_token;
			cmd_token = strtok(NULL, " \n");
			i++;
		}
		cmd_args[i] = NULL;

		if (strcmp(cmd_args[0], "exit") == 0)
		{
			free(line);
			free(cmd_args);
			exit(22);
		}
		if (strcmp(cmd_args[0], "env") == 0 && cmd_args[1] == NULL)
		{
			while (envp[j] != NULL)
			{
				write(STDOUT_FILENO, envp[j], _strlen(envp[j]));
				write(STDOUT_FILENO, &nl, 1);
				j++;
			}
		}
		else if (strcmp(cmd_args[0], "cd") == 0)
		{
			if (cmd_args[1] == NULL)
				K_cd(getenv("HOME"));
			else
				K_cd(cmd_args[1]);
		}
		else
		{
			child_p = fork();
			if (child_p == -1)
			{
				perror("Process failed.");
				exit(23);
			}
			if (child_p == 0)
			{
				if (execve(cmd_args[0], cmd_args, envp) == -1)
				{
					if (cmd_args[0] != NULL)
					{
						perror("./hsh");
						exit(12);
					}
				}
			}
			else
			{
				wait(&status);
			}
		}
	}
	return (0);
}
