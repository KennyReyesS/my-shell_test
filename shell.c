#include "simple_shell.h"
/**
 *main - Shell program.
 *@argc: unused.
 *@argv: command argument.
 *@env: pointer to the enviroment list.
 *Return: 0
 */
int main(int argc __attribute__((unused)), char *argv[], char **env)
{
	char *buf = NULL;
	size_t sizebuf = 0;
	ssize_t userInput = 0;

	shellname = argv[0];/*aqui declare el name para imprimir el caso de error*/
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1) /* si es un descriptor abierto conectado a una terminal */
			write(STDOUT_FILENO, "$ ", 2); /* imprime el prompt "$ " */
		userInput = getline(&buf, &sizebuf, stdin); /* lee una linea de texto desde el teclado */
		if (userInput == -1) /* Si userInput da error */
		{
			if (isatty(STDIN_FILENO) == 1) /* escribe un salto de linea en la terminal */
				write(STDOUT_FILENO, "\n", 1);
			break; /* y termina el programa */
		}

		if (buf[userInput - 1] == '\n') /* Si  */
			buf[userInput - 1] = '\0';
		if (*buf == '\0') /* Si el usuario no escribe nada continua el programa*/
			continue;
		if (tokenize_cmd(buf, env) == 2) /* para poner userInput tuve que declararlo en la funcion con atribute */
			break; /* Si el comando es exit termina el programa */
	}
	free(buf); /* al terminar el programa libera el buf */
	buf = NULL; /* y vuelve a tener el valor de NULL */
	return (0);
}

/**
 *tokenize_cmd - tokenizes each command entered by the user.
 *@buf: command entered by the user.
 *@env: pointer to the enviroment list.
 *Return: the enviroment if the user types "env", the execution of the command,
 *or 2 if the user types exit (this ends the program).
 */
int tokenize_cmd(char *buf, char **env)
{
	char *token;
	char *array[100];
	int i = 0; /* aqui el valor de i lo puse arriba, el otro lo puso despues de strtok */

	if (_strcmp(buf, "exit", 4) == 0)
		return (2); /* cambiar return para probar poniendo una funcion que salga del programa */
	if (_strcmp(buf, "env", 3) == 0) /* si el comando ingresado por el usuario es "env" ejecuta */
		return (_printenv(env)); /* la funcion printenv */
	token = strtok(buf, DELIM); /* tokenizamos la cadena separandolos por los delimitadores dentro de DELIM (estos estan en el .h) */
	while (token)
	{
		array[i++] = token;
		token = strtok(NULL, DELIM); /* una vez que no hayan mas delimitadores termina el tokenizador */
	}
	array[i] = NULL; /* el final del array termina en NULL */
	return (_execute(array)); /* ejectura lo que se haya almacenado en array */
}

/**
 *_execute - executes the command stored in the array.
 *@array: array of the commands.
 *Return: 0, or 1 in exit.
 */

int _execute(char *array[])
{
	char *exec_path = NULL;
	char *cmd = NULL;
	pid_t pid;
	int status;

	cmd = array[0];
	exec_path = searchpath(cmd, environ); /* la funcion searchpath buscara el comando dentro del env y lo almacenara en exec_path */
	if (exec_path == NULL) /* Si no se encontro el comando ejecuta */
	{
		not_path(cmd); /* funcion por si no se encontro el path */
		return (0);
	}
	pid = fork(); /* de lo contrario crearemos un hijo */
	if (pid < 0) /* si da error */
	{
		perror("Error:");
		return (-1);
	}
	if (pid > 0) /* es padre y espera el estado del hijo */
	{
		wait(&status);
	}
	else if (pid == 0) /* es hijo y ejecuta el comando*/
	{
		(execve(exec_path, array, environ));
		perror("Error:");
		exit(1);
	}
	free(exec_path); /* libera memoria dentro del exec_path */
	return (0);
}

void not_path(char *cmd)
{
	write(STDOUT_FILENO, shellname, _strlen(shellname)); /* name se declara en el main y es argv[0] */
	write(STDOUT_FILENO, ": 1: ", 5); /* n debería ser parte de una funcion que incremente un contador por cada prompt impreso */
	write(STDOUT_FILENO, cmd, _strlen(cmd)); /* nombre del comando escrito por el usuario */
	write(STDOUT_FILENO, ": not found\n", 12);
}
