#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork + wait + exceve
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t pid;
	int status;
	int i;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}

		/* child process */
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
			perror("execve");
			return (-1);
		}

		/* parent process */
		else
		{
			wait(&status);
		}
	}
	return (0);
}
