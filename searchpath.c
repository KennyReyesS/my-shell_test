#include "simple_shell.h"

/**
 *searchpath - seek in the PATH, using the tokenizer for each directory
 *and puts the executable in the final of the PATH if it's found.
 *@cmd: Command entered by user.
 *@env: pointer to the string of the enviroment list.
 *Return: no seeeeeeeeeeeeeeeeeeeeeeeeeeee
 */

char *searchpath(char *cmd, char **env)
{
	char *path = _strdup(_getenv("PATH", env));
	int i = 0;
	int j = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = cmd;
	char *new_path = NULL;
	struct stat buf;

	new_path = malloc(sizeof(char) * 100);
	if (_getenv("PATH", env)[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (_strdup(cmd));
	while (path_tokens != NULL)
	{
		path_array[i++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	for (j = 0; path_array[j]; j++)
	{
		_strcpy(new_path, path_array[j]);
		_strcat(new_path, "/");
		_strcat(new_path, s2);
		_strcat(new_path, "\0");

		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);

	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));
	return (NULL);
}
