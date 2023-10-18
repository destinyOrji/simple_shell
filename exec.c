#include "shell.h"
/**
 * execute_command - executes a command
 * @args: the arguments to the cmd
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	if (access(args[0], X_OK) == 0)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Process creation failed");
			exit(2);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Couldn't execute command.");
				exit(3);
			}
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		perror("Executable not found:");
	}
}