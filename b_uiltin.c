#include "shell.h"
/**
 * exit_ins - exit command.
 * @list_command: list of command
 * Return: nothing.
 */
int exit_ins(char **list_command)
{
	if (list_command[1] == NULL)
		return (1);
	return (1);
}

/**
 * env_ins - write variable enviromen.
 *
 * Return: Always int.
 */
int env_ins(void)
{
	int size, i = 0;

	while (environ[i] != NULL)
	{
		size = _strlen(environ[i]);
		write(1, environ[i], size);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
