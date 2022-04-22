#include "shell.h"
/**
 * _getenv - get a environ variable.
 * @name: environ variable
 *
 * Return: Always int.

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
 * _strchr - localate a character in a string.
 * @s: string
 * @c: character
 *
 * Return: Always 0.

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

 * _path_dir - values path.
 * @comd: line entered.
 * Return: a char.
 */

/**
 * _strncmp - compare a string with the number of bits
 * @path: first string
 * @match: second string
 * @n: number th bits to be compared
 * Return: return the path if find a match
 */
char *_strincmp(char *path, char *match, size_t n)
{
	while (n && *path && (*path == *match))
	{
		++path;
		++match;
		--n;
	}
	if (n == 0)
	{
		return (path);
	}
	else
	{
		return (NULL);
	}
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

char *_path_dir(char *comd)
{
	char *path, *rout;
	char *delim = ":\n";
	char *comand;
	int i = 0;
	struct stat st;

	while (environ[i])
		{
		if (_strincmp(environ[i], "PATH", 4) != NULL)
		{
			path = _strdup(environ[i]);
			break;
		}
		i++;
	}
	if (!path)
		return (NULL);

	rout = strtok(path, delim);

	while (rout != NULL)
	{
		if (stat(comd, &st) == 0)
			return (comd);
		comand = malloc(sizeof(char) * (_strlen(rout) + _strlen(comd) + 2));
		_strcpy(comand, comd);
		if (comand == NULL)
		{
			return (NULL);
		}

		comand = _strcat(comand, rout);
		comand = _strcat(comand, "/");
		comand = _strcat(comand, comd);

		if (stat(comand, &st) == 0)
		{
			free(rout);
			free(comd);
			return (comand);
		}
		rout = strtok(NULL, delim);
	}

	free(comand);
	free(rout);
	return (NULL);
}
