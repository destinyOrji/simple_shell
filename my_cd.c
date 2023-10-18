#include "main.h"
/**
 * K_cd - change directory
 * @directory: changes the directory
 */
void K_cd(char *directory)
{
	if (directory == NULL)
	{
		directory = getenv("HOME");
	}
	if (chdir(directory) != 0)
	{
 		perror("couldn't change directory");
	}
}
