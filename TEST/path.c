#include "shell.h"
/**
 * _getenv - get a environ variable.
 * @name: environ variable
 *
 * Return: Always int.
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *vble, *var;
	int a = 0;

	a = _strlen((char *)name);

	for (; environ[i] != NULL; i++)
	{
		vble = environ[i];
		var = _strchr(vble, '=');

		if (var && (((var - vble) == a) && !_strncmp(vble, (char *)name, a)))
		{
			return (var + 1);
		}
	}
	return (NULL);
}
/**
 * _strchr - localate a character in a string.
 * @s: string
 * @c: character
 *
 * Return: Always 0.
 */

char *_strchr(char *s, char c)
{
	int j;

	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] == c)
			return (&s[j]);
	}
	return (0);
}
/**
 * _path_dir - values path.
 * @comd: line entered.
 * Return: a char.
 */
char *_path_dir(char *comd)
{
	char *path, *rout;
	char *delim = ":\n";
	char *comand;
	struct stat st;

	path = _getenv("PATH");
	rout = strtok(path, delim);

	while (rout != NULL)
	{
		if (stat(comd, &st) == 0)
			return (comd);
		comand = malloc(sizeof(char) * (_strlen(rout) + _strlen(comd) + 2));
		if (comand == NULL)
		{
			return (NULL);
		}

		comand = _strcat(comand, rout);
		comand = _strcat(comand, "/");
		comand = _strcat(comand, comd);

		if (stat(comand, &st) == 0)
		{
			return (comand);
		}
		rout = strtok(NULL, delim);
	}

	free(comand);
	free(rout);
	return (NULL);
}
