#include "shell.h"

char *getpath(void)
{
        char *path;

        while (*environ)
        {
                if (!_strncmp(*environ, "PATH", 4))
                {
                        path = strtok(*environ, "=");
                        path = strtok(NULL, "=");
                        return (path);
                }
                environ++;
        }
        return (NULL);
}

size_t print_list(const list_p *h)
{
        size_t count = 0;
        const list_p *next_p = NULL;

        if (h == NULL)
                return (0);
        next_p = h;
        do {
                count++;
                if (next_p->dirname != NULL)
                        printf("%s\n", next_p->dirname);
                else
                        printf("(nil)\n");
                next_p = next_p->next;
        } while (next_p != NULL);
        return (count);
}

list_p *get_last(list_p **head)
{
        list_p *last;

        last = *head;
        while (last->next != NULL)
        {
                last = last->next;
        }
        return (last);
}

list_p *add_node_end(list_p **head, const char *str)
{
        list_p *new, *last;

        new = malloc(sizeof(list_p));
        if (new == NULL)
                return (NULL);

        new->dirname = strdup(str);
        if (new->dirname == NULL)
        {
                free(new);
                return (NULL);
        }

        new->next = NULL;

        if (*head == NULL)
                *head = new;
	else
        {
                last = get_last(head);
                last->next = new;
        }

        return (*head);
}

int file_found(char *path)
{
        struct stat st;

        if (stat(path, &st) == 0)
        {
                return (1);
        }
        else
        {
                return (0);
        }
}

list_p *create_list(void)
{
	list_p *head;
	char *path = getpath();
	char *dirpath;

	head = NULL;
	dirpath = strtok(path, ":");
	while (dirpath)
	{
		add_node_end(&head, dirpath);
		dirpath = strtok(NULL, ":");
	}
	//print_list(head);
	return (head);
}

int main(void)
{
	list_p *head;
	char *cmd = "/ls";
	char *newpath;

	head = create_list();
	while (head->next)
	{
		newpath = _strcat(head->dirname, cmd);
		if(file_found(newpath))
			printf("%s: Found\n", newpath);
		else
			printf("%s: Not Found\n", newpath);
		head = head->next;
	}
	return (0);
}
