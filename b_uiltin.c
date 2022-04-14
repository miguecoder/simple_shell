#include "shell.h"
/**
 *
 *
 */
int exit_ins(void)
{
	return (1);
}

/**
 *
 *
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
