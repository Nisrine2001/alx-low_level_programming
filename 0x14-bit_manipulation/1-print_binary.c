#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 * @n: numbers to printed in binary
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1 b is NULL
 */
void print_binary(unsigned long int n)
{
int bytes = sizeof(n) * 8, printed = 0;
while (bytes)
{
if (n & 1L << --bytes)
{
putchar('1');
printed++;
}
else if (printed)
putchar('0');
}
if (printed)
putchar('0');
}
