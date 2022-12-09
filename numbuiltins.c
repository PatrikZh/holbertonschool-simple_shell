#include "main.h"

char *builtin_str[] = {
	"cd",
	"exit"
};

int (*builtin_func[]) (char **) = {
	_cd
	_exit
};

/**
 * number_bultins - function
 * Return: result
 */
int number_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}
