#include "main.h"
/**
* strlen - calculate and return string lengt
*  @s: string
*  Return: string length
*/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
* string_nconcat - function that concatenates two strings
* @s1: string1
* @s2: string2
* @n: n bytes to concat from string2
*
* Return: pointer to concatenated string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int len = n, index, num, j;
	char *concat;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (len < 0)
		return (NULL);
	if (len >= _strlen(s2))
		len = _strlen(s2);
	num = _strlen(s1) + len +1;
	concat = malloc(sizeof(*concat) * num);
	if (concat == NULL)
		return (NULL);
	for (index = 0; s1[index] != '\0'; index++)
		concat[index] = s1[index];
	for (j = 0; j < len; j++)
		concat[index + j] = s2[j];
	concat[index + j] = '\0';
	return (concat);
}
