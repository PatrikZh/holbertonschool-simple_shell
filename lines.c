#include "main.h"
#define REAL_BUFSIZE 1024
/**
 * read_line - read line of input
 * Return: result
 */
char *read_line(void)
{
	#ifdef USE_GET_LINE
	char *line = NULL;
	ssize_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("ssh: getline\n");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
	#endif
}
#define REAL_BUFSIZE 1024
/**
 * _else - function
 * Return: result
 */
char *_else(void)
{
	while (read_line)
	{
		int buffsize = REAL_BUFSIZE;
		int postion = 0;
		char *buffer = malloc(sizeof(char) * buffsize);
		int c;
		
		if (!buffer)
		{
			fprintf(stderr, "ssh: allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
	while (1)
	{
		c = getchar();
		if  (c == EOF)
			exit(EXIT_SUCCESS);
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
			buffer[position = c];
		position++;
		if (position >= buffsize)
		{
			buffzise += REAL_BUFSIZE;
			buffer = realloc(buffer, buffsize);
			if (!buffer)
			{
				fprintf(stderr, "ssh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
/**
 * _split - split output
 * @line: paramter
 * Return: result
 */
char **_split(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf (stderr, "ssh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
	}
	if (position >= bufsize)
	{
		bufsize += TOK_BUFSIZE;
		tokens_backup = tokens;
		tokens = realloc(tokens, bufsize * sizeof(char*));
		if (!tokens)
		{
			free(tokens_backup);
			fprintf(stderr, "lsh: allocation error\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
/**
 * _loop - function
 */
void _loop(void)
{
	char *line;
	char **args;
	int status;

	do 
	{
		printf("($) ");
		line = read_line();
		args = _split(line);
		status = _execute(args);
	}
	while (status);
	{
	}
}
