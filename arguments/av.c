#include <stdio.h>

/**
 * main - program that prints all the arguments, without using ac
 * @ac: agrument count
 * @av: argument vector
 *
 * Return : always 0
 */
int main(int ac, char **av)
{
	int i = 0;

	(void)ac;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}