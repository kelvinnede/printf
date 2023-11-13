#define _GNU_SOURCE
#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf_b - Handle %b conversion specifier.
 * @args: Variable arguments.
 *
 * Return: The number of characters printed.
 */
int _printf_b(va_list args)
{
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	print_binary(num);

	return (count);
}
