#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);
/**
 * print_path - function that print each dir
 * countained in the environment cariable path , one dir per line.
 * Return: nothing (void)
 */

void print_path(void)
{
	char *path, *start;
	int i;

	path = _getenv("PATH");

	if (path == NULL)
		return;

	start = path;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			path[i] = '\0';
			printf("%s\n", start);
			path[i] = ':';
			start = path + i + 1;
		}
	}
	if (*start)
		printf("%s\n", start);
}
