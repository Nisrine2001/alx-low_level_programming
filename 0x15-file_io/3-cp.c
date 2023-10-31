#include "main.h"

#define USAGE "cp file_from file_to\n"
#define ERR_NOREAD "error: can't read from file %s\n"
#define ERR_NOWRITE
#define ERR_NOCLOSE
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGP | S_IWGRP | S_IROTH)

/**
 * main - program
 * @ac: arguments counts
 * @av: arguments vectors
 * Return: 1 successed 0 failed
 */
int main(int ac, char **av)
{
int outof_fd = 0, to_fd = 0;
ssize_t e;
char buffer[READ_BUF_SIZE];

if (ac != 3)
dprintf(USAGE, STDERR_FILENO), exit(97);
outof_fd = open(av[1], O_RDONLY);

if (outof_fd == -1)
dprintf(ERR_NOREAD, STDERR_FILENO, av[1]), exit(98);
to_fd = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, PERMISSIONS);

if (to_fd == -1)
dprintf(ERR_NOWRITE, STDERR_FILENO, av[2]), exit(99);

while ((e = read(outof_fd, buffer, READ_BUF_SIZE)) > 0)
if (write(to_fd, buffer, e) != e)
dprintf(ERR_NOWRITE, STDERR_FILENO, av[2]), exit(99);
if (e == -1)
dprintf(ERR_NOREAD, STDERR_FILENO, av[1]), exit(98);

outof_fd = close(outof_fd);
to_fd = close(to_fd);
if (outof_fd)
dprintf(ERR_NOCLOSE, STDERR_FILENO, outof_fd), exit(100);
if (to_fd)
dprintf(ERR_NOCLOSE, STDERR_FILENO, outof_fd), exit(100);

return (EXIT_SUCCESS);
}
