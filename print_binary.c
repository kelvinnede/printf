#include "main.h"

/**
 * print_binary - Print binary representation of an unsigned integer.
 * @num: Unsigned integer to be printed in binary.
 */
void print_binary(unsigned int num)
{
	int size = sizeof(unsigned int) * 8;
	int binary[32];

	int i;

	for (i = 0; i < size; i++)
	{
		binary[i] = num % 2;
		num /= 2;
	}

	for (i = size - 1; i >= 0; i--)
	{
		_putchar('0' + binary[i]);
	}

	_putchar('\n');
}
