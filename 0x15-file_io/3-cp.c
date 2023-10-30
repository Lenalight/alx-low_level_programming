#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if files can be opened.
 * @file_from: file_from.
 * @file_to: file_to.
 * @argv: arguments vector.
 * Return: no return.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - copy the content of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: 0 on success, error codes on failure.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open(argv[1], O_RDONLY);
	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (from_fd == -1 || to_fd == -1)
		error_file(from_fd, to_fd, argv);

	while ((nchars = read(from_fd, buf, 1024)) > 0)
	{
		if (nchars == -1)
			error_file(-1, to_fd, argv);
		nwr = write(to_fd, buf, nchars);
		if (nwr == -1)
			error_file(from_fd, -1, argv);
	}

	err_close = close(from_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		exit(100);
	}

	err_close = close(to_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
		exit(100);
	}

	return (0);
}

