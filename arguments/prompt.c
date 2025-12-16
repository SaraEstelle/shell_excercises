#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that prints "$ ", wait for the user
 * to enter a command, prints it on the next line.
 * Return : always 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$");
	nread = getline(&line, &len, stdin);
	if (nread == -1) /* EOF (Ctrl+D) */
	{
		free(line);
		return (0);
	}
	printf("%s", line);
	free(line);

	return (0);
}
