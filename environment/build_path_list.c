#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path_list.h"

char *_getenv(const char *name);

path_t *build_path_list(void)
{
	char *path = _getenv("path");
	char *start, *end;
	path_t *head = NULL, *node, *tail = NULL;

	if (!path)
		return (NULL);

	start = path;
	while (*start)
	{
		end = start;
		while (*end && *end != ':')

			end++;

		node = malloc(sizeof(path_t));
		if (!node)
			return (NULL);

		node->dir = strndup(start, end - start);

		if (!node->dir)
		{
			free(node);
			return (NULL);
		}
		node->next = NULL;
		if (!head)
			head = node;
		else
			tail->next = node;

		tail = node;

		if (*end == ':')
			end++;
		start = end;
	}
	return (head);
}
