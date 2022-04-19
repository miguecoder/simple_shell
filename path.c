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
 * error_command - function error
 * @copy: comando completo
 * Return: nothing
 */
void error_command(char *copy)
{
	char *msj_error;
	int length = 0;

	msj_error = malloc((sizeof(char) * _strlen(copy)) + 9);
	if (msj_error == NULL)
	{
		free(msj_error);
		return;
	}
	_strcat(msj_error, "./hsh: ");
	_strcat(msj_error, "1");
	_strcat(msj_error, ": ");
	_strcat(msj_error, copy);
	_strcat(msj_error, ": not found\n");
	length = _strlen(msj_error);
	write(1, msj_error, (length + 1));
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
	}

	free(comand);
	free(rout);
	return (NULL);
}
