#include "shell.h"
/**
 * signal_c - Signal handlig
 * @signal: ctrl c
 * Return: nothing
 *
 */
void signal_c(__attribute__((unused))int signal)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "SHELL_GOD$ ", 12);
}
/**
 * main - Funtion that give a signal and call shell function
 * Return: 0 alwayls.
 */
int main(void)
{
	signal(SIGINT, signal_c);
	shell();
	return (0);
}
