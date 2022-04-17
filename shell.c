#include "shell.h"
/**
 * get_command - This function read the input line
 * int the shell and create a array with this strings
 * Return: a string with the comand line
 */
char *get_command(void)
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
 * @command: line command
 * @copy: copy line
 * @list_token: line command tokens
 * Return: 0 always
 */
void check_builtin(int (*f)(), char *command, char *copy, char **list_token)
{
	if (f)
	{
		if (f() == 1)
		{
			free(command);
			free(copy);
			free(list_token);
			exit(127);
		}
	}
}
/**
 * shell - While loop infinite
 * Return: 0
 */
int shell(void)
{
	int (*function)();
	char *command, *copy, **list_token;

	while (1)
	{
		char *prompt = "SHELL_GOD$ ";

		if (isatty(STDIN_FILENO))
			write(1, prompt, 10);
		command = get_command();
		if (command == NULL)
			return (0);
		if (command && command[0] != '\n')
		{
			copy = malloc(sizeof(char) * _strlen(command) + 1);
			if (!copy)
			{
				free(copy);
				return (0);
			}

			_strcpy(copy, command);
			list_token = tk_cm(copy, " \n\t\r");
			function = get_builtins(list_token[0]);
			check_builtin(function, command, copy, list_token);
			execution(list_token, copy);
			free(copy);
			free(list_token);
		}
		free(command);
	}
	return (0);
}
