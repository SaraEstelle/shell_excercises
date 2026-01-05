#include <stdlib.h>
#include <string.h>
#include "path_list.h"

char **build_path_list(void)
{
	char *path;
	char *copy;
	char **dirs;
	int i = 0, count = 1;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	/*count ':' */
	for (i = 0; path[i]; i++)
		if (path[i] == ':')
			count++;

	dirs = malloc(sizeof(char *) * (count + 1));
	if (!dirs)
		return (NULL);

	copy = strdup(path);
	if (!copy)
		return (NULL);

	i = 0;
	dirs[i] = strtok(copy, ":");
	while (dirs[i])
	{
		dirs[i] = strdup(dirs[i]);
		i++;
		dirs[i] = strtok(NULL, ":");
	}
	dirs[i] = NULL;

	free(copy);
	return (dirs);
}
