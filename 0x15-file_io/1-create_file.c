#include "main.h"

/**
 * _strlen - length of the strng
 * @s: string
 * Return: length
 */
int _strlen(char *s);

int _strlen(char *s)
{
	int l = 0; /* length */

	while (*s++)
		l++;
	return (l);
}

/**
 * create_file - creates a file.
 * @filename: name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int fd_write;

	fd = open(filename, O_CREAT | O_WRONLY | O_RDWR, 0600);
	if (fd == -1)
		return (-1);

	if (!(text_content))
	{
		close(fd);
		return (1);
	}
	fd_write = write(fd, text_content, _strlen(text_content));
	if (fd_write == -1 || fd_write != _strlen(text_content))
	{
		close(fd);
		return (-1);
	}
	close(fd);

	return (1);
}
