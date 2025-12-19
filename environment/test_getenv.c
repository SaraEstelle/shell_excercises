#include <stdio.h>

char *_getenv(const char *name);

/**
 * main - test _getenv
 *
 * Return: Always 0
 */
int main(void)
{
	printf("PATH = %s\n", _getenv("PATH"));
	printf("HOME = %s\n", _getenv("HOME"));
	printf("SHELL = %s\n", _getenv("SHELL"));
	printf("FAKE = %s\n", _getenv("FAKE"));

	return (0);
}
