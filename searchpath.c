#include "simple_shell.h"

/**
 *searchpath - seek in the PATH, using the tokenizer for each directory
 *and puts the executable in the final of the PATH if it's found.
 *@cmd: Command entered by user.
 *@env: pointer to the string of the enviroment list.
 *Return: new_path, directory PATH followed by /"command" entered by the user
 */

char *searchpath(char *cmd, char **env)
{
	char *path = _strdup(_getenv("PATH", env)); /* *path almacenara la linea del path despues del "=" (/usr/local/bin:/bin/:...) */
	int i = 0;
	int j = 0;
	char *path_tokens = strtok(path, ":"); /* parte el *path (el mencionado arriba) para que sea /usr/local/bin: | /bin/ | ...*/
	char *path_array[100]; /* se le asigna un espacio limite de 100 al array para ser usado abajo */
	char *s2 = cmd; /* cmd es el comando ingresado por el usuario ls, echo, etc. */
	char *new_path = NULL; /* se le da NULL, para luego utilizarlo mas abajo y asignarle espacio en memoria */
	struct stat cmd_stat; /* para poder utilizar la funcion stat necesitamos agregarle un struct stat */

	new_path = malloc(sizeof(char) * 100); /* al new_path que estaba en NULL ahora tendra espacio en memoria de 100 */
	while (path_tokens != NULL) /* aqui es donde le decimos al strtok que continue hasta que no se encuentre el ":" */
	{
		path_array[i++] = path_tokens; /* los tokens (/usr/local/bin:, /bin/, etc) son convertidos en arrays */
		path_tokens = strtok(NULL, ":"); /* cuando no haya ":" para el while */
	}
	path_array[i] = NULL; /* el ultimo sera NULL */
	for (j = 0; path_array[j]; j++) /* Aqui es donde se va a poner el ejecutable al final del array, por ejemplo: /bin/ls <- */
	{
		_strcpy(new_path, path_array[j]); /* este es el directorio por ejemplo: /bin/ */
		_strcat(new_path, "/"); /* y a partir de aqui se inserta el nombre del programa al final. por ejemplo: "/ls" */
		_strcat(new_path, s2);
		_strcat(new_path, "\0");

		if (stat(new_path, &cmd_stat) == 0)  /* check it worked*/ /* revisa si "/bin/ls" existe */
		{
			free(path); /* si existe, libera memoria del path */
			return (new_path); /* y nos retorna felizmente el new_path para ser usado en el execve del main: "/bin/ls" */
		}
		else
			new_path[0] = 0;
	}
	free(path); /* se libera memoria del path */
	free(new_path); /* se libera memoria del new_path */

	if (stat(cmd, &cmd_stat) == 0) /* Con esto funciona el modo interactivo */
	  return (_strdup(cmd));
	return (NULL);
}
