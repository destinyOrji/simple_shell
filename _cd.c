#include "shell.h"
/**
 * _cd - a function that changes directory
 * @path: The path
 */
void _cd(char *path);
void _cd(char *path)
{
	char *new_path;
	char current_path[PATH_MAX];

	if (strcmp(path, "-") == 0)
	{
		new_path = getenv("OLDPWD");
		if (new_path == NULL)
		{
			perror("Couldn't get path");
		}
	}
	else
	{
		if (path == NULL)
		{
			new_path = getenv("HOME");
		}
		else
		{
			new_path = path;
		}
	}

	if (getcwd(current_path, sizeof(current_path)) == NULL)
	{
		perror("Path not found");
	}
	else
	{
		if (setenv("OLDPWD", current_path, 1) !=  0)
		{
			perror("Couldn't set dir");
		}
		if (chdir(new_path) == -1)
		{
			perror("Path not found");
		}
		else
		{
			if (setenv("PWD", new_path, 1) != 0)
			{
				perror("Couldn't set path");
			}
		}
	}
}
