#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "main.h"

/**
 * _strlen - return a length of a string
 * @a: string length to check
 *
 * Return: integer length to the string
 */
int _strlen(char *a)
{
int pr = 0;

if (!a)
return (0);

while (*a++)
pr++;

return (pr);

}
/**
 * create_file - creates a file with specific permissions
 *
 * @filename: name of the file to create
 * @text_content: text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int fd;
ssize_t n = 0, len = _strlen(text_content);

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

if (len)
n = write(fd, text_content, len);
close(fd);
return (n == len ? 1 : -1);

}
