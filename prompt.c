#include "shell.h"
/**
 * display_prompt - displays the prompt
 */
void display_prompt()
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
