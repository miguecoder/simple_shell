#include "shell.h"
/**
 * execution - Function for the child process
 * @list_token: double pointer to the tokens of line comand
 * @copy: line comand got.
 * Return: 0 always.
 */
int execution(char **list_token, char *copy)
{
	pid_t pidC;
	char *rout;
	int status;
	int error_numbs = 0;

	pidC = fork();

	if (pidC == -1)
	{
		perror("Creation of a child process was unsuccessful!");
		exit(-1);
	}
	if (pidC == 0)
	{
		rout = _path_dir(list_token[0]);
		execve(rout, list_token, environ);
		error_numbs = errno;
		error_input(error_numbs, copy);
		free(rout);
		exit(0);
	}
	else
	{
		pidC = wait(&status);
	}
	return (0);
}
