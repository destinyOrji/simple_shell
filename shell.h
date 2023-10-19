#ifndef MAIN_H
#define MAIN_H

/*Header files*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/*Prototypes*/
void display_prompt(void);
char **parse_command(char *line);
void free_args(char **args);
void execute_command(char **args);
int _strlen(char *s);
ssize_t _getline(FILE *fp, char **lineptr, size_t *n);

#endif /*MAIN_H*/
