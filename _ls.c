#include "shell.h"
/**
 * _ls - mimics the ls command
 * @envp: environment variable passed from main
 * @args: the array passed to the function
 */
void _ls(char **envp, char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Could't create process");
		exit(0);
	}

	if (pid == 0)
	{
		if (execve("/bin/ls", args, envp) == -1)
		{
			perror("Couldn't execute ls");
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
