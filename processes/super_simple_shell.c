#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;
/**
 * main - super simple shell
 *
 * Return : Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;

	while (1)
	{
		/* prompt */
		write(STDOUT_FILENO, "$", 2);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		/* remove trailling newline */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		/* Child */
		if (pid == 0)
		{
			char *argv[] = {line, NULL};
			execve(argv[0], argv, environ);
			perror("execve");
			exit(1);
		}
		/* Parent */
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
