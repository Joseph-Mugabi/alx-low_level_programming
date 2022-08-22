#include "main.h"

/**
 * read_textfile -  reads a text file and prints it
 * to the POSIX standard output.
 * @filename: name of the file to create.
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 * if filename is NULL return 0, if write fails or does not
 * write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf_letters;
	ssize_t fd_read, fd_write;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf_letters = malloc(sizeof(char) * letters);
	if (buf_letters == NULL)
		return (0);

	fd_read = read(fd, buf_letters, letters);
	if (fd_read == -1)
	{
		free(buf_letters);
		close(fd);
		return (0);
	}
	fd_write = write(STDOUT_FILENO, buf_letters, fd_read);
	if (fd_write == -1)
	{
		free(buf_letters);
		close(fd);
		return (0);
	}
	close(fd);
	return (fd_read);
}
