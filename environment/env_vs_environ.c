#include <stdio.h>

extern char **environ;

/**
 * main - program that compare between env and environ
 *
 *@ac: argument count
 *@av: argument vector
 *@env: environment
 *
 * Return : Always  0.
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("Adress of env : %p\n", (void *)env);
	printf("Adress of environ : %p\n", (void *)environ);

	return (0);
}
