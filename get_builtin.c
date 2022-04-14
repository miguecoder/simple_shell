#include "shell.h"
/**
 *
 */
int (*get_builtins(char *stt))()
{
	int i;
	built_t funct[] = {
	{"env", env_ins}.
	{"exit", exit_ins},
	{NULL,NULL}
	};

	for (i = 0; funct[i].key != NULL; i++)
	{
		if (_strcmp(funct[i].key, s) == 0)
		{
			return (funct[i].function);
		}
	}
	return (0);
}
