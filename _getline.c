#include "shell.h"
/**
 * _getline - mimics the getline function
 * @fp: the file pointer
 * @lineptr: a pointer to the line
 * @n: the buffer
 *
 * Return: returns the length of the line
 */
ssize_t _getline(FILE *fp, char **lineptr, size_t *n)
{
	int ch;
	size_t len = 0;
	char *temp = NULL;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	while ((ch = fgetc(fp)) != EOF && ch != '\n')
	{
		if (len >= *n - 1)
		{
			*n += 128;
			temp = realloc(*lineptr, *n);
			if (temp == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1);
			}
			*lineptr = temp;
		}
		(*lineptr)[len++] = ch;
	}
	if (ch == EOF && len == 0)
	{
		return (-1);
	}
	(*lineptr)[len] = '\0';
	return (len);
}
