# _0x15. C - Simple Shell_

## Description
In this project we are tasked with creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

Our shell does what a shell normally does, it opens files, creates files, you can modify files with vim, compile programs with gcc, list files and other common shell functions.  

## How to used it
- Compiling the program: 
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
- Use the program with:
```sh
./shs
```
## You can use it in:
- Interactive mode:
```sh
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
- Non-interactie mode:
```sh
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
___
___

## Files

| FILE | WHAT DOES |
| ------ | ------|
| b_uiltin.c | Function that look for a builtin (env and exit). |
| ct_word.c | Functions that count how many word have the command. |
| error_input.c | Function that prints error messages related to "not found" and "permission denied". |
| execution.c | Function for the child process. |
| get_builtin.c | Function that get function env and exit. |
| otr_commds.c | helper functions. |
| path.c | finds PATH. |
| shell.c | While loop infinite. |
| shell.h | Header file with prototypes and structures. |
| token.c | Function that split a string. |

___
___

## Project Requirements

1. All your files will be compiled on Ubuntu 20.04 LTS using gcc
2. All your files should end with a new line
3. A README.md file, at the root of the folder of the project is mandatory
4. Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
5. Your shell should not have any memory leaks
6. No more than 5 functions per file
7. Use system calls only when you need to

___
___

## Functions Shell

| FUNTION | WHAT DOES |
| ------ | ------|
| *_getenv | get a environ variable |
| *get_command | This function read the input line |
| **tk_cm | get token of the string |
| *_path_dir | values path |
| execution | create fork. |

___
___

## Functions Error

| FUNTION | WHAT DOES |
| ------ | ------|
| error_input | Funtion for error in line comand |

___
___

# Output

- Example of error with sh: 
```sh
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
- Same error with your program hsh:
```sh
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
___
___

# Authors!!
- MIGUEL MARQUEZ - "@miguecoder"
- SANTIAGO OSORNO - "@santiago1411"
___
___
