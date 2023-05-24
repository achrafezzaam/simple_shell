#include "shell.h"

size_t _strlen(const char *input)
{
        size_t count = 0;

        while (*input)
        {
                count++;
                input++;
        }
        return (count);
}

int _strcmp(char *s1, char *s2)
{
        while (*s1)
        {
                if (*s1 != *s2)
                        return (1);
                s1++;
                s2++;
        }
        return (0);
}
