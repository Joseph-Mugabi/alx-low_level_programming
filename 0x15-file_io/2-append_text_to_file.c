#include "main.h"

/**
 * _strlen - find the lenght of a string.
 * @s: array of characters.
 *
 * Return: lenght of the string.
 */
int _strlen(char *s);
int _strlen(char *s)
{
	int l;

	while (*s++)
		l++;

	return (l);
}

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, fd_write;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		fd_write = write(fd, text_content, _strlen(text_content));
		if (fd_write == -1)
			return (-1);
	}
	close(fd);

	return (1);
}
