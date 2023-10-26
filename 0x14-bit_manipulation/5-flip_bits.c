#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would need to flip
 * to get from one number to another
 * @n: the number to bit
 * @m: number two to flip
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int bit_nis = n ^ m;
unsigned int turnover = 0;

while (bit_nis)
{
turnover += bit_nis & 1;
bit_nis >>= 1;
}

return (turnover);
}
