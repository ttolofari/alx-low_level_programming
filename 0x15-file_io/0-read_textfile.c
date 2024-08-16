#include <stdio.h>
#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * read_textfile - reads a text file and prints it to the POSIX
 * standard output.
 * @filename: name of file.
 * @letters: Number of letters it should read and print.
 * Return: Actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, res_read, res_write;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	res_read = read(fd, buffer, letters);
	if (res_read == -1)
	{
		free(buffer);
		return (0);
	}
	res_write = write(STDOUT_FILENO, buffer, res_read);
	if (res_write == -1 || res_read != res_write)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(fd);
	return (res_write);
}
