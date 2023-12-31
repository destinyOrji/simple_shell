#ifndef MAIN_H
#define MAIN_H

/*Header files*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <limits.h>



/*Prototypes*/
void display_prompt(void);
char **parse_command(char *line);
void free_args(char **args);
int _strlen(char *s);
ssize_t _getline(FILE *fp, char **lineptr, size_t *n);
int _strcmp(char *s1, char *s2);
void K_cd(char *directory);
void K_ls(char **path);
void _ls(char **envp, char **args);
void _cd(char *path);
int _atoi(char *s);
int execute_command(char **args, char **envp);
void exit_shell(char **args);
char **parse_commands(char *line);

#endif /*MAIN_H*/
