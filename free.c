#include "shell.h"
/**
 * free_args - free a particular array
 * @args: the array to be freed
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
