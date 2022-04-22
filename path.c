#include "shell.h"
/**
 * _getenv - get a environ variable.
 *
 * Return: Always int.
 */

char *_getenv(void)
{
	int i = 0;
	char *path = NULL;

	while (environ[i])
	{
		if (_strncmp(environ[i], "PATH", 4) == 0)
		{
			path = _strdup(environ[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}
/**
 * _strdup - returns a pointer to a newly allocated space
 * @s: string to be duplicated
 * Return: a pointer to new string
 */
char *_strdup(char *s)
{
	int i;
	char *dup;
	int len;

	if (s == NULL)
	{
		return (NULL);
	}
	len = _strlen(s);
	dup = malloc((sizeof(char) * len) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';
	return (dup);
}
/**
 * _path_dir - values path.
 * @comd: line entered.
 * Return: a char.
 */
char *_path_dir(char *comd)
{
	char *path = NULL, **rout = NULL;
	char *comand = NULL;
	int i = 1;
	struct stat st;

	path = _getenv();
	rout = tk_cm(path, "=:");
	while (rout[i] != NULL)
	{
		if (stat(comd, &st) == 0)
		{
			comand = _strdup(comd);
			free(rout);
			free(path);
			return (comand);
		}
		comand = malloc(sizeof(char) * (_strlen(rout[i]) + _strlen(comd) + 2));
		if (comand == NULL)
		{
			free(comand);
			return (NULL);
		}
		_strcpy(comand, rout[i]);
		_strcat(comand, "/");
		_strcat(comand, comd);
		if (stat(comand, &st) == 0)
		{
			free(path);
			free(rout);
			return (comand);
		}
		free(comand);
		i++;
	}

	free(path);
	free(rout);
	return (NULL);
}
