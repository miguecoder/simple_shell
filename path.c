#include "shell.h"
/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(const char *var)
{
	int index, len;

	len = _strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
/**
 * _strdup - duplicate the strins s.
 * @s: string to duplicate
 *
 * Return: string.
 */

char *_strdup(const char *s)
{
	int i;
	char *dup;
	int len;

	if (s == NULL)
	{
		return (NULL);
	}

	len = strlen(s);
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
 *
 * Return: a char.
 */
char *_path_dir(char *comd)
{
	char *path, *rout;
	char *delim = ":\n";
	char *comand;
	struct stat st;


	if (stat(comd, &st) == 0)
		return (comd);

	path = _getenv("PATH");
	rout = strtok(path, delim);

	while (rout != NULL)
	{
		comand = malloc(sizeof(char) * (_strlen(rout) + _strlen(comd) + 2));
		if (comand == NULL)
		{
			return (NULL);
		}

		memset(comand, 0, (_strlen(rout) + _strlen(comd)));
		comand = _strcat(comand, rout);
		comand = _strcat(comand, "/");
		comand = _strcat(comand, comd);

		if (stat(comand, &st) == 0)
		{
			rout = _strdup(comand);
			return (comand);
		}
		rout = strtok(NULL, delim);
		rout++;
	}
	free(comand);
	free(rout);
	return (NULL);
}
