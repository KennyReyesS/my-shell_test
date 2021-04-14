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
		length = _strlen(environ[i]); /* almacena la longitud del env */
		write(STDOUT_FILENO, environ[i], length); /* y lo imprime con la funcion write */
		write(STDOUT_FILENO, "\n", 1); /* luego salta la linea */
		i++;
	}
	return (0);
}

/**
 *_getenv - get the env if a user type other command (no "exit", no "env")
 *@name: pointer to the name of the environment variable
 *@env: pointer char to the string of the enviroment list.
 *Return: The direction of the directories of env variable or "Not found".
 */

char *_getenv(const char *name, char **env)
{
	int i = 0;
	int j = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);
	while (env[i] != NULL) /* mientras el env no sea nulo */
	{
		while (env[i][j] == name[j]) /* si encuentra el nombre de la variable de entorno por ejemplo la variable PATH */
			j++; /* revisara la linea donde se encuentra la variable de entorno, por ejemplo PATH=/usr/local/sbin:/usr/local/bin: */
		if (env[i][j] == '=') /* si encuentra un = */
		{
			j++; /* avanza j */
			return (&(env[i][j])); /* retorna la direccion de la variable de entorno despues del = por ejemplo en el caso del PATH:
						  solo retornara: /usr/local/sbin:/usr/local/bin: */
		}
		i++;
		j = 0;
	}
	write(STDOUT_FILENO, "Not found", 9); /* si no encuentra la variable de entorno imprimira Not found */
	return (NULL);
}
