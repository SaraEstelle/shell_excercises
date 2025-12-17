#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE 128

/**
 * _getline - read a line from stdin
 * @lineptr: pointer to buffer
 * @n: size of buffer
 *
 * Return: number of chars read, or -1 on EOF
 */

ssize_t _getline(char **lineptr, size_t *n)
{
	ssize_t i = 0;
	char c;
	char *tmp;

	if (!lineptr || !n)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = READ_SIZE;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}
	while (1)
	{
		ssize_t r = read(STDIN_FILENO, &c, 1);
		if (r == -1)
			return (-1);
		if (r == 0) /*EOF*/
		{
			if (i == 0)
				return (-1);
			break;
		}

		if (i + 11 >= (ssize_t)*n)
		{
			*n *= 2;
			tmp = realloc(*lineptr, *n);
			if (!tmp)
				return (-1);
			*lineptr = tmp;
		}
		(*lineptr)[i++] = c;
		if (c == '\n')
			break;
	}
	(*lineptr)[i] = '\0';
	return (i);
}
