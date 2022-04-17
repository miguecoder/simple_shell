#include "shell.h"
/**
 * ct_word- word counter
 * @strn: string a count.
 * @delim: delimitator.
 *
 * Return: letter.
 */
int ct_word(char *strn, char *delim)
{
	int ct = 0;
	int letter = 0;

	while (*strn)
	{
		if (*strn == *delim || *strn == '\n' || *str == '\t')
			ct = 0;

		else if (ct == 0)
		{
			ct = 1;
			letter++;
		}
		strn++;
	}
	return (letter);
}
