#include "main.h"

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments
 * @argv: pointer to content of arguments
 *
 * Return: 1 to succes
 */
int main(int argc, char *argv[])
{
	int fd_open1, fd_open2, fd_read, close1, close2;
	char array[1024], error1[] = "Error: Can not read from file NAME_OF_THE_FILE";
	char error2[] = "Error: Can not write from file NAME_OF_THE_FILE";

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from_to\n");
		exit(97);
	}
	fd_open1 = open(argv[1], O_RDONLY);
	if (fd_open1 < 0)
	{
		dprintf(STDERR_FILENO, "%s %s\n", error1, argv[1]);
		exit(98);
	}
	fd_open2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_open2 < 0)
	{
		dprintf(STDERR_FILENO, "%s %s\n", error2, argv[2]);
		exit(99);
	}
	while ((fd_read = read(fd_open1, array, 1024)) > 0)
	{
		if (write(fd_open2, array, fd_read) != fd_read)
		{
			dprintf(STDERR_FILENO, "%s %s\n", error2, argv[2]);
			exit(98);
		}
	}
	close1 = close(fd_open1);
	close2 = close(fd_open2);
	if ((close1 == -1) || (close2 == -1))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", argv[1]);
		exit(100);
	}
	return (0);
}
