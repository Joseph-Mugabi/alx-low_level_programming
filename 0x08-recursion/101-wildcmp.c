#include "main.h"

/**
* substring_match - chech if a substring after wildcard matches s1.
* @s1: first string1
* @s2: second string
* @after_wild: placeholder for postion right after wildcard
* Return: 1 if matched, 0 if not.
*/
int substring_match(char *s1, char *s2, char *after_wild)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	if (*s1 == '\0' && *s2 == '*')
		return (substring_match(s1, s2 + 1, s2 + 1));
	if (*s1 == '\0' && *s2 != '0')
		return (0);
	if (*s2 == '*')
		return (substring_match(s1, s2 + 1, s2 + 1));
	if (*s1 == *s2)
		return (substring_match(s1 + 1, s2 + 1, after_wild));
	else
		return (substring_match(s1 + 1, after_wild, after_wild));
}
/**
* wildcmp - compare if string with wildcard matches.
* @s1: first string1
* @s2: second string2
*
* Return: 1 if matched, 0 if not.
*/
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (substring_match(s1, s2 + 1, s2 + 1));
	else
		return (0);
}
