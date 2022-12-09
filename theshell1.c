#include "main.h"
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
		if (strcmp(args[0], builtin_str[i]) == 0) {
			return (builtin_func[i](args));
		}
	}
	return(_launch(args));
}
