#include "shell.h"
int handle_path(int argc, char *argv[])
{
    char *path;
    char *path_copy;
    char full_path[MAX_PATH_LENGTH];
    char *token;

    path = getenv("PATH");
    path_copy = strdup(path);

    token = strtok(path_copy, ":"); // Tokenize command using ":" as the delimiter

    while (token != NULL)
    {
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", token, argv[0]);
        if (access(full_path, F_OK) == 0)
        {
            argv[0] = full_path; // Replace the command with the full path
            free(path_copy);
            return 0;
        }
        token = strtok(NULL, ":");

    }


    free(path_copy);
    return 1;
}
