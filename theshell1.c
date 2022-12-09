#include "main.h"
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
/**
 * _launch - launch function
 * @args: the entered arguments
 * Return: result
 */
int _launch(char **args)
{

	pid_t my_pid;
	int status;

       	my_pid = fork();
	if (my_pid == 0)
	{
    		if (execvp(args[0], args) == -1)
		{	
			perror("lsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (my_pid < 0)
	{
		perror("ssh");
	}
	waitpid(my_pid, &status, WUNTRACED);
	return 1;
}
/**
 * _execute - execute function
 * @args: the entered arguments
 * Return: result
 */
int _execute(__attribute__((unused)) char **args)
{
	int i;

	if (args[0] == NULL)
		return 1;
	for (i = 0; i < number_builtins(); i++) {
		if (strcmp(args[0], builtin_str[i] == 0)) {
			return (*builtin_func[i](args));
		}
	}
	return(_launch(args));
}
