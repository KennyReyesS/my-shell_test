#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define DELIM " \t\0"

extern char **environ;
char *shellname;

int tokenize_cmd(char *buf, char **env);
int _execute(char *array[]);
void not_path(char *cmd);

int _printenv(char **environ);
char *_getenv(const char *name, char **env);
char *searchpath(char *cmd, char **env);

char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);

#endif
