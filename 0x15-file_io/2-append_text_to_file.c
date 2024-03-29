#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, fd_write, l = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (text_content == NULL)
	{
		return (1);
	}
	while (text_content[l])
		l++;
	fd_write = write(fd, text_content, l);
	if (fd_write < 0)
	{
		return (-1);
	}
	close(fd);

	return (1);
}
