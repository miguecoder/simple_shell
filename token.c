#include "shell.h"
/**
 * tk_cm - Function that create a tokens for line comand
 * @comand: line of input in linecomand
 * Return: array that contents all tokenof line comand
 */
char **tk_cm(char *comand, char *delim)
{
	char **token = NULL;
	int i, word = 0;

	word = ct_word(comand, " ");
	
	token = malloc(sizeof(char *) * (word + 1));
	if (token == NULL)
	{
		free(token);
		return(NULL);
	}

	token[0] = strtok(comand, delim);
	for (i = 1; i < word; i++)
		token[i] = strtok(NULL, delim);
	return (token);
}
/**
 * tk_path -
 * @
 * Return:
 */
void tk_path()
{
}
