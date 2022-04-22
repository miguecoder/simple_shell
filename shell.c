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
		free(buffer);
		exit(0);
	}
	return (buffer);
}
/**
 * check_builtin - Function
 * @f: funtion to check
 * @command: line comand
 * @buffer: memory space
 * Return: 0 always
 */
void check_builtin(int (*f)(), char **buffer, char *command)
{
	if (f)
	{
		if (f() == 1)
		{
			free(command);
			free(buffer);
			exit(127);
		}
	}
}
/**
 * shell - While loop infinite
 * Return: void
 */
int shell(void)
{
	int (*function)(), error_numbs;
	char *command = NULL, **list_token = NULL, *path = NULL;

	while (1)
	{
		char *prompt = "SHELL_GOD$ ";

		if (isatty(STDIN_FILENO))
			write(1, prompt, _strlen(prompt));
		command = get_command();
		if (command == NULL)
			continue;
		list_token = tk_cm(command, " \n\t");
		function = get_builtins(list_token[0]);
		check_builtin(function, list_token, command);
		path = _path_dir(list_token[0]);
		if (path)
		{
			if (execution(list_token, path) == -1)
			{
				error_numbs = errno;
				error_input(error_numbs, command);
				free(path);
				free_tokens(list_token);
				continue;
			}
			else
			{
				free(path);
				free(list_token);
				free(command);
				continue; }
		}
		else
		{
			free(path);
			free_tokens(list_token);
			continue; }
	}
	return (0);
}
