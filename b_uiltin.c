#include "shell.h"
/**
 * exit_ins - exit command.
 * Return: nothing.
 */
int exit_ins(void)
{
	return (1);
}

/**
 * env_ins - write variable enviromen.
 *
 * Return: Always int.
 */
int env_ins(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
