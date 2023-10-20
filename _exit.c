#include "shell.h"
/**
 * exit_shell - exit the function
 * @args: the status
 */
void exit_shell(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
	{
		exit_status = _atoi(args[1]);
	}
	exit(exit_status);
}
