#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
/**
 * _setenv - sets or updates an environment variable
 * @name: variable name
 * @value: variable value
 * @overwrite: 1 to replace existing value, 0 otherwise
 *
 * Return: 0 on success, -1 on failure
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t len;
	int i;
	char *new_var;

	if (!name || !value || strchr(name, '='))
		return (-1);

	len = strlen(name);

	/* Cherche si la variable existe deja */
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 &&
			environ[i][len] == '=')
		{
			if (!overwrite)
				return (0);

			new_var = malloc(len + strlen(value) + 2);
			if (!new_var)
				return (-1);

			sprintf(new_var, "%s=%s", name, value);
			environ[i] = new_var;
			return (0);
		}
	}
	/* Variable does not exist*/
	return (0);
}
