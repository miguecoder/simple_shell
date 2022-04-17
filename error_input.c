#include "shell.h"
/**
 * error_input - Funtion for error in line comand
 * @errno: number of last error
 * @copy: incoming command
 * Return: nothing
 */
void error_input(int errno, char *copy)
{
	char *msj_error;
	int length = 0;

	msj_error = malloc((sizeof(char) * _strlen(copy)) + 9);
	if (msj_error == NULL)
	{
		free(msj_error);
		return;
	}
	_strcat(msj_error, "hsh: ");
	_strcat(msj_error, '1');
	_strcat(msj_error, ": ");
	_strcat(msj_error, copy);

	if (errno == 14)
	{
		_strcat(msj_error, ": not found\n");
		length = _strlen(msj_error);
		write(STDOUT, msj_error, (length + 1));
	}
	else
		perror(msj_error);
	free(copy);
	free(msj_error);
}
