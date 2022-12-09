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
/**
 * _cd - changes directory
 * @args: the entered arguments
 * Return: result
 */
int _cd(__attribute__((unused)) char **args)
{
        if (args[1] ==  NULL)
        {
                fprintf (stderr, "ssh: expected to \"cd\"\n");
        }
        else if (chdir(args[1]) != 0)
        {
                perror("ssh");
        }
        return 1;
}
/**
 * _exit - exit out of shell
 * @args: the entered arguments
 * Return: result
 */
int __exit(__attribute__((unused)) char **args)
{
        return 0;
}
char *builtin_str[] = {
        "cd",
        "exit"
};

int (*builtin_func[]) (char **) = {
        _cd,
        __exit
};

/**
 * number_bultins - function
 * Return: result
 */
int number_builtins() {
        return sizeof(builtin_str) / sizeof(char *);
}

#endif
