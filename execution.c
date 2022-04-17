#include "shell.h"
/**
 * execution - Function for the child process
 * @list_token: double pointer to the tokens of line comand
 * @copy: line comand got.
 * Return: 0 always.
 */
int execution(**list_token, *copy)
{
	pid_t pidC;
	char *rout;
	int status;

	pidC = fork();

	if (pidC > 0)
	{
		pidC = wait(&status);
	}
	else if (pidC == 0)
	{
		rout = _path_dir(list_token[0]);
		execve = (rout, list_token, environ);
		error_input(errno, copy);
		free(rout);
		exit(0);
	}
	else
	{
		perror("Creation of a child process was unsuccessful!");
		exit(-1);
	}
	return (0);
}
