#include <stdio.h>
#include <unistd.h>
/**
 * main - program that prints the PID
 * of the parent process.
 * Return : Nothing
 */
int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();

	printf("%u\n", parent_pid);

	return (0);
}
