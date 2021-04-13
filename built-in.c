#include "simple_shell.h"

/**
 *_printenv - print the env if the user type "env".
 *@environ: pointer char to the string of the enviroment list.
 *Return: 0
 */

int _printenv(char **environ)
{
	int i = 0, length = 0;

	while (environ[i] != NULL)
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0); /* cambie el void por int en prototype para poner el return 0 */
}

/**
 *_getenv - get the env if a user type other command (no "exit", no "env")
 *@name: pointer to the first argument.
 *@env: pointer char to the string of the enviroment list.
 *Return: the string to the command in the path or NULL if "Not found".
 */

char *_getenv(const char *name, char **env)
{
	int i = 0;
	int j = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		while (env[i][j] == name[j])
			j++;
		if (env[i][j] == '=')
		{
			j++;
			return (&(env[i][j]));
		}
		i++;
		j = 0;
	}
	write(STDOUT_FILENO, "Not found", 9);
	return (NULL);
}
