#include <stdio.h>

int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);

int main(void)
{
	printf("OLD PATH = %s\n", _getenv("PATH"));

	_setenv("PATH", "/my/custom/path", 1);
	printf("NEW PATH = %s\n", _getenv("PATH"));

	_setenv("NEWVAR", "hello", 0);
	printf("NEWVAR = %s\n", _getenv("NEWVAR"));

	_setenv("NEWVAR", "world", 0);
	printf("NEWVAR (overwrite=0) = %s\n", _getenv("NEWVAR"));

	_setenv("NEWVAR", "world", 1);
	printf("NEWVAR (overwrite=1) = %s\n", _getenv("NEWVAR"));

	return (0);
}
