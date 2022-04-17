#include "shell.h"
/**
 * _strncmp - copies a string in long array.
 * @str1: string 1
 * @str2: string 2
 * @n: The maximum number of characters to be compared.
 *
 * Return: Always 0.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t m;
	size_t p;

	for (m = 0; str1[m] != '\0' && m < n; m++)
	{
		p = str1[m] - str2[m];
		if (p != 0)
		{
			return (p);
		}
	}
	return (0);
}
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	i++;
	}
	return (0);
}
/**
 * _strlen - return lenght of the string.
 * @s: string
 *
 * Return: Always int.
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strcpy - copies the string pointed to by src into dest
 * @dest: destination of the copy
 * @src: source of the copy
 *
 * Return: char pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0;

	if (src == NULL)
		perror("error");

	for (; src[len] != '\0'; len++)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}
/**
 * _strcat - concatenate two strings.
 * @dest: first string
 * @src: string added to dest
 *
 * Return: string.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
