#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _unsetenv - deletes a variable from the environment
 * @name: name of the variable to delete
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	size_t len;
	int i, j;

	if (!name || strchr(name, '='))
		return (-1);

	len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 &&
			environ[i][len] == '=')
		{
			/* décaler tous les éléments suivants vers la gauche */
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
			/* vérifier le nouvel élément à cette position */
			return (0);
		}
	}
	return (0);
}
