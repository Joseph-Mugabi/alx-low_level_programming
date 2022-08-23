#include "main.h"

/**
 *  _close_ - close a opened file
 *  @fd: file descriptor
 */

void _close_(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments
 * @argv: pointer to content of arguments
 * Return: 1 to succes
 */

int main(int argc, char *argv[])
{
	int fdo1, fdo2, fdr, fdw;
	char arr[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fdo1 = open(argv[1], O_RDONLY);
	if (fdo1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fdo2 = open(argv[2], O_TRUNC | O_CREAT | O_WRONLY, 0664);
	if (fdo2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
		exit(99);
	}
	do {
		fdr = read(fdo1, arr, 1024);
		if (fdr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		fdw = write(fdo2, arr, fdr);
		if (fdw != fdr || fdr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
			exit(99);
		}
	} while (fdr == 1024);
	_close_(fdo1);
	_close_(fdo2);
	return (0);
}
