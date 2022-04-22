#include "shell.h"
/**
 * count_word - Functions that count how many word have the command
 * @strn: String that contains the line command got
 * Return: number of words.
 */
int count_word(char *strn)
{
	int ct = 0;
	int word = 0;

	while (*strn)
	{
		if (*strn == ' ' || *strn == '\n' || *strn == '\t' || *strn == '='
				|| *strn == ':')
			ct = 0;

		else if (ct == 0)
		{
			ct = 1;
			word++;
		}
		strn++;
	}
	return (word);
}
