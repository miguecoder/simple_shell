#include "shell.h"
/**
 * get_comand - This function read the input line
 * int the shell and create a array with this strings
 * Return: a string with the comand line
 */
char get_comand(void)
{
	char *buffer = NULL;
	size_t size = 0; /*Number of bytes*/
	int length = 0; /*except the null \0*/
	/*
	 * getline create a buffer with enough size for save the
	 * input for the command line
	 */
	length = getline(&buffer, &size, stdin); /*stdio.h*/
	if (length == EOF)
	{
		write(1, "SHELL_GOD$ ", 10);
		exit(0);
	}
	return (buffer);
}
/**
 * check_builtin - Function
 * @f: funtion to check
 * Return: 0 always
 */
void check_builtin(int (*f)())
{
	if (f)
	{
		if (f() == 1)
		{
			free(comand);
			free(copy);
			free(list_token);
			exit(127);
		}
		continue;
	}
	;
}
/**
 * shell - While loop infinite
 * Return: 0
 */
int shell(void)
{
	int (*function)();
	char *comand, *copy, **list_token;
	long counter;
	int i, status;

	while (1)
	{
		char *prompt = "SHELL_GOD$ ";

		if (isatty(STDIN_FILENO))
			write(1, prompt, 10);
		comand = get_comand();
		if (comand == NULL)
			return (0);
		if (comand && comand[0] != '\n')
		{
			copy = malloc(sizeof(char) * _strlen(comand) + 1);
			if (!copy)
			{
				free(copy);
				return (0);
			}

			_strcpy(copy, comand);
			list_token = tk_cm(copy, " \n\t\r");
			function = get_bultins(list_token[0]);
			check_builtin(function);
			execution(list_token, copy);
			free(copy);
			free(list_token);
		}
		free(comand);
	}
	return (0);
}
