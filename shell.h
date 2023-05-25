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

extern char **environ;
char *str_dup(char *str);
void my_puts(const char *str);
void child_process(char *str, char **argv, char **env, char **av);
int _putchar(char x);
void prompt(char **av, char **env);
char *get_location(char *command);
int str_cmp(char *x, char *y);
char *str_cat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
int str_len(char *y);
int strn_cmp(const char *str1, const char *str2, size_t n);
void sig_handle(int sig);

#endif
