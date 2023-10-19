#include "shell.h"
/**
 * K_ls - a function that list the files in a directory
 * @path: the directory
 */

void K_ls(char *path[])
{
	if (execve("/bin/ls", path, NULL) == -1)
	{
		perror("./hsh: ");
	}
}
