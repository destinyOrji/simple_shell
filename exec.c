#include "shell.h"
/**
 * execute_command - executes a command
 * @args: the arguments to the cmd
 * @envp: the environment variable passed from the main function
 *
 * Return: returns the exit status
 */
int execute_command(char **args, char **envp)
{
	pid_t pid;
	int status;

	if (access(args[0], X_OK) == 0)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Process creation failed");
			return (1);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, envp) == -1)
			{
				perror("Couldn't execute command.");
				exit(2);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			return (WEXITSTATUS(status));
		}
	}
	perror("./hsh");
	return (1);
}
