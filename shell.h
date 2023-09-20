#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define delimeter " \t\n"

extern char **environ;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);

char **string_token(char *buffer);
char *_getline(void);
int exec(char **ptr1, char **ptr2, int idx);
char *get_env(char *name);
char *get_path(char *name);
void print_error(char *name, char *tmp, int j);
void rev_string(char *s, int i);
char *rev_help(int n);
int bultin(char *command);
void handling(char **command, char **av, int *status, int idx);
void exit_func(char **command, char **av, int *status, int idx);
void env_func(char **command, int *status);
int atoi(char *str);
void positive(char *str);

#endif
