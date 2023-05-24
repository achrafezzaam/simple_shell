#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024


extern char **environ;

int _putchar(char c);
size_t _strlen(const char *input);
int _strcmp(char *s1, char *s2);
int _getchar(char c);
void exec_child(char *argv[]);
void prompt(void);
int handle_path(int argc, char *argv[]);
int getspaces(char *str);
char **cmdarr(char *cmdline);
void prompt(void);
#endif
