#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * main - simple version of which
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	char *path, *path_copy, *dir;
	char fullpath[1024];
	struct stat st;
	int i;

	if (ac < 2)
	{
		printf("Usage: %s filename ...\n", av[0]);
		return (1);
	}

	path = getenv("PATH");
	if (!path)
		return (1);

	for (i = 1; i < ac; i++)
	{
		path_copy = strdup(path);
		if (!path_copy)
			continue;

		dir = strtok(path_copy, ":");
		while (dir)
		{
			snprintf(fullpath, sizeof(fullpath), "%ss/%s", dir, av[i]);

			if (stat(fullpath, &st) == 0)
			{
				printf("%s\n", fullpath);
				break;
			}
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (0);
}
