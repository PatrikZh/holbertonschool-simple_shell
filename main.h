#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int _cd(__attribute__((unused)) char **args);
int __exit(__attribute__((unused)) char **args);
int _launch(__attribute__((unused)) char **args);
int _execute(__attribute__((unused)) char **args);
char *read_line(void);
char *split_line(char *line);
void _loop(void);
int number_builtins();
char *_else(void);
char **_split(char *line);
int main(__attribute__((unused)) int argc,__attribute__((unused)) char **argv);


#endif
