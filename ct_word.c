#include "shell.h"
/**
 * count_word - Functions that count how many word have the command
 * @strn: String that contains the line command got
 * @delim: Delimiter for each word
 * Return: number of words.
 */
int count_word(char *strn, char *delim)
{
	int ct = 0;
	int word = 0;

	while (*strn)
	{
		if (*strn == *delim || *strn == '\n' || *strn == '\t')
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
