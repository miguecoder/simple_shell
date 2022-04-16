#include "shell.h"
/**
 *
 *
 */
int ct_word(char *strn, char *delim)
{
	int ct = 0;
	int word = 0;

	while (*strn)
	{
		if (*strn == *delim || *strn == '\n' || *str == '\t')
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
