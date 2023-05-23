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
/**
 * struct path_list - to represent a linked list of directory names
 *
 * @dirname: Name of the directory
 *
 * @next: Pointer to the next node in the linked list
 */
typedef struct path_list
{
	char *dirname;          /* Name of the directory */
	struct path_list *next; /* Pointer to the next node in the linked list */
} list_p;


int _putchar(char c);
size_t _strlen(const char *input);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *str1, char *str2);
int _getchar(char c);
void exec_child(char *argv[]);
void prompt(void);

int getspaces(char *str);
char **cmdarr(char *cmdline);
char **patharr(char *cmdline);

void _print(char *str);

char *file_exist(char *cmd);
char *_strdup(char *str);

#endif
