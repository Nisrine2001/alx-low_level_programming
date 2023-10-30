#include "main.h"

/**
 * read_textfile - function that reads a text file
 * and prints it to the POSIX standard output
 * @filename: string pointer contain the file name
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t n;
char buffer[READ_BUF_SIZE * 8];

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

n = read(fd, &buffer[0], letters);
if (n == -1)
{
close(fd);
return (0);
}

n = write(STDOUT_FILENO, &buffer[0], n);
if (n == -1)
{
close(fd);
return (0);
}
return (n);

}
