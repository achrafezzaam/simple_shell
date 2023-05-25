#ifndef ALX_HEADER
#define ALX_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

int _strlen(char *str);
char *_strdup(char *str);
int get_count(char *str, char delim);

char **cmdarr(char *str);

#endif
