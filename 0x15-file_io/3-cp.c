#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: Name of the file buffer is storing chars for.
 *
 * Return: A pointer to the new-allocated buffer.
 */
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (buffer);
}

/**
 * close_file - Closes file descriptors
 * @fd: The file descriptor to be close
 */
void close_file(int fd)
{
int a;

a = close(fd);

if (a == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * main - program that copies the content of a file to another file
 * @ac: arguments counts
 * @av: arguments vectors
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_outof does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int ac, char *av[])
{
int outof, to, rea, wrt;
char *buffer;

if (ac != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_outof file_to\n");
exit(97);
}

buffer = create_buffer(av[2]);
outof = open(av[1], O_RDONLY);
rea = read(outof, buffer, 1024);
to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (outof == -1 || rea == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", av[1]);
free(buffer);
exit(98);
}

wrt = write(to, buffer, rea);
if (to == -1 || wrt == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", av[2]);
free(buffer);
exit(99);
}

rea = read(outof, buffer, 1024);
to = open(av[2], O_WRONLY | O_APPEND);

} while (rea > 0);

free(buffer);
close_file(outof);
close_file(to);

return (0);
}
