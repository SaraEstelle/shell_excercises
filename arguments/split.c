#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_line - splits a string and returns an array
 * of each word of the string
 * @line: input string
 *
 * Return: NULL - terminated arrays of strings
 */

char **split_line(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);

	token = strtok(line, "\t\n");
	while (token != NULL)
	{
		token[i++] = token;
		token = strtok(NULL, "\t\n");
	}
	token[i] = NULL;

	return (tokens);
}
