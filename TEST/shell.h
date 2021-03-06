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
 * struct built_ins - singly linked list
 * @key: variable
 * @function: function
 */

typedef struct built_ins
{
	char *key;
	int (*function)();
} built_t;

void signal_c(__attribute__((unused))int signal);
int main(void);
int shell(void);
int env_ins(void);
int exit_ins(void);
char *get_command(void);
int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int count_word(char *strn, char *delim);
int (*get_builtins(char *stt))();
void check_builtin(int (*f)(char **b));
int execution(char **list_token, char *copy);
char **tk_cm(char *comand, char *delim);
void error_input(int err_no, char *copy);
char *_path_dir(char *comd);
char *_getenv(const char *name);
char *_strchr(char *s, char c);
char *_strdup(char *s);
char *_strincmp(char *path, char *match, size_t n);
#endif
