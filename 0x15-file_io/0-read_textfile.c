#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file to read and print
 * @letters: number of letters it should read and print
 * Return: actual number of letters read and printed or 0 if the file cannot be
 * open or read, filename is NULL, or write fails or does not return expected
 * amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	int bytes; /* number of bytes read by read syscall */

	if (filename == NULL || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	bytes = read(fd, buffer, letters);
	if (bytes == -1)
		return (0);

	write(STDOUT_FILENO, buffer, bytes);

	close(fd);

	free(buffer);

	return (bytes);
}

