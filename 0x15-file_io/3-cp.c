#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
* main - copies content of file to another file
* @argc: number of arguments
* @argv: pointer to string of arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *file_from, *file_to;
	char buffer[BUFLEN];
	int fd_to, fd_from = 0;
	int read_ret, write_ret, close_from_ret, close_to_ret;

	if (argc != 3)
		exit(exit_error(97, NULL, 0));
	if (argv[1] == NULL)
		exit(exit_error(98, argv[1], 0));

	file_from = argv[1], file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		exit(exit_error(98, file_from, fd_from));

	fd_to = open(file_to, O_CREAT | O_TRUNC | O_WRONLY, 00664);
	if (fd_to == -1)
		exit(exit_error(99, file_to, fd_to));

	read_ret = read(fd_from, buffer, BUFLEN);
	if (read_ret == -1)
		exit(exit_error(98, file_from, fd_from));

	while (read_ret != 0)
	{
		write_ret = write(fd_to, buffer, read_ret);
		if (write_ret == -1)
			exit(exit_error(99, file_to, fd_to));
		read_ret = read(fd_from, buffer, BUFLEN);
	}

	close_from_ret = close(fd_from);
	if (close_from_ret == -1)
		exit(exit_error(100, file_from, fd_from));
	close_to_ret = close(fd_to);
	if (close_to_ret == -1)
		exit(exit_error(100, file_to, fd_to));

	return (0);
}

/**
* exit_error - print error and return number for exit status
* @num: error number
* @str: string to print in error
* @fd: file descriptor
* Return: exit status number
*/
int exit_error(int num, char *str, int fd)
{
	int status = 0;

	switch (num)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		status = 97;
		break;

	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
		status = 98;
		break;

	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
		status = 99;
		break;

	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		status = 100;
		break;
	}

	return (status);
}

