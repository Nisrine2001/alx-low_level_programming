#include "main.h"

/**
 *_strlen - return a length of a string
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
 * append_text_to_file - function that appends text at the end of a file
 * @filename: name of the file to create
 * @text_content: text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd;
ssize_t n = 0, len = _strlen(text_content);

if (!filename)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

if (len)
n = write(fd, text_content, len);
close(fd);
return (n == len ? 1 : -1);

}
