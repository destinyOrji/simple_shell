#include "main.h"
/**
 * _strlen - a function to recursively calculate
 * the length of a string
 * @s: the string whose length is to be calculated
 * Return: returns the length of the string
 */
int _strlen(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + (_strlen(s + 1)));
}
