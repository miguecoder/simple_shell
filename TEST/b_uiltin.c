#include "shell.h"
/**
 * exit_ins - exit command.
 * @list_command: list of command
 * Return: nothing.
 */
int exit_ins(char **list_command)
{
	if (list_command[1] == NULL)
		return (0);
	return (1);
}

/**
 * env_ins - write variable enviromen.
 *
 * Return: Always int.
 */
int env_ins(void)
{
	return (0);
}
