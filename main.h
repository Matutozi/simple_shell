#ifndef _MAIN_H
#define _MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFERSIZE 1024
extern char **environ;

ssize_t prompt(char *chr);
char *_strdup(char *str);
size_t _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *string1, const char *string2);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
ssize_t read_cmd(char **cmd, size_t *len);
char **parse_cmd(char *cmd);
int execute_cmd(char *cmd);
char *find_path(char *command);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void print_environment(void);
#endif /*MAIN_H */

