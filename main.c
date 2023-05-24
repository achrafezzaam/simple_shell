#include "shell.h"

int main(void)
{
    ssize_t count;
    size_t len = 0;
    char *line = NULL;
    char **argv;

    prompt();
    while ((count = getline(&line, &len, stdin)) != -1)
    {
        line[count - 1] = '\0';
        if (!_strcmp(line, "exit"))
        {
            break;
        }
        argv = cmdarr(line);
        handle_path(count, argv); // Handle the path for each command
        exec_child(argv);
        prompt();
    }
    if (count == -1)
        _putchar('\n');
    free(line);
    return 0;
}
