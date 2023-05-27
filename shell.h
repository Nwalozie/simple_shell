#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_COMMAND 20
#define DISPLAY(c) (write(STDOUT_FILENO, c, str_len(c)))

extern char **environ;
char *_itoa(int n);
void not_found(char *input, int line, char **cmd);
int count_num(int n);
char *str_dup(char *str);
void my_puts(const char *str);
void child_process(char *str, char **argv, char **av, int line);
int _putchar(char x);
void prompt(char **av);
char *get_location(char *command);
int str_cmp(char *x, char *y);
char *str_cat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
int str_len(char *y);
int strn_cmp(const char *str1, const char *str2, size_t n);

#endif
