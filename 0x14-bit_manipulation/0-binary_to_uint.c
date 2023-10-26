#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: is pointing to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1 b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int a = 0;
if (!b)
return (0);

while (*b)
{
if (*b != '0' && *b != '1')
return (0);

a = a * 2 + (*b++ - '0');
}
return (a);
}
