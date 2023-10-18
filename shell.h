#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

void display_prompt();
char **parse_command(char *line);
void free_args(char **args);
void execute_command(char **args);


#endif /*MAIN_H*/
