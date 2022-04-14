#ifndef _SHELL_H_
#define _SHELL_H_

#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

/**
 * struct built - singly linked list
 * @key: variable
 * @function: function
 */

typedef struct built_ins
{
	char *key;
	int (*function)();
} built_t;


int main(void);
int shell(void)
int env_ins(void);
int exit_ins(void);
char get_commando(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);


#endif
