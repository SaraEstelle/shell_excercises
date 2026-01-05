#include <stdio.h>

int _unsetenv(const char *name);
char *_getenv(const char *name);

int main(void)
{
	printf("PATH = %s\n", _getenv("PATH"));
	_unsetenv("PATH");
	printf("PATH après _unsetenv = %s\n", _getenv("PATH"));

	_unsetenv("FAKEVAR"); /* test variable non existante */

	return (0);
}
