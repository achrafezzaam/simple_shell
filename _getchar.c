#include "shell.h"
int _getchar(char c)
{
        return (read(0, &c, 1));
}
